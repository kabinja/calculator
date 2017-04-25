#include "parser.h"
#include "state.h"

Token Parser::currentToken() const
{
    return m_tokens.peek();
}

void Parser::nextToken()
{
    m_tokens.next();
}

Node Parser::parseExpression(State::Level level)
{
    Node expression = parseBranch(level);

    if(!expression.isValid())
    {
        return expression;
    }

    bool breakLoop = false;

    State currentState;

    for(;;)
    {
        switch (currentToken().type()) {
        case Token::Type::Add:
            currentState.set(State::Level::level07, State::Level::level08,
                             [](double left, double right) { return left + right;});
            break;

        default:
            breakLoop = true;
            break;
        }

        if(breakLoop)
        {
            break;
        }
        else if(currentState.left() < level)
        {
            break;
        }

        nextToken();

        Node rightBranch;
        Node newExpression;

        rightBranch = parseExpression(currentState.right());
        if(rightBranch.isValid())
        {
            newExpression.set((currentState.operation())(rightBranch.value(), expression.value()));
        }

        if(!newExpression.isValid())
        {
            return Node();
        }
        else
        {
            expression = newExpression;
        }
    }

    return expression;
}

Node Parser::parseBranch(State::Level level)
{
    Node branch;

    if(Token::Type::Digit == currentToken().type())
    {
        branch.set(currentToken().value());
        nextToken();
    }

    return branch;
}

Parser::Parser()
{

}

std::string Parser::expression() const
{
    return m_tokens.expression();
}

std::string Parser::answer() const
{
    return m_answer;
}

void Parser::addToken(std::string s)
{
    m_tokens.append(s);
}

void Parser::removeToken()
{
    m_tokens.pop();
}

void Parser::clearExpression()
{
    m_tokens.clear();
}

void Parser::evaluate()
{
    if(m_tokens.isEmpty())
    {
        m_answer.clear();
    }
    else
    {
        m_tokens.reset();
        Node expression = parseExpression();
        m_answer = std::to_string(expression.value());
    }
}


