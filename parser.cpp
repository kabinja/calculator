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
        return Node();
    }

    State currentState;

    for(;;)
    {
        if(!updateState(currentState))
        {
            return expression;
        }

        if(currentState.left() < level)
        {
            break;
        }

        nextToken();

        Node rightBranch;
        Node newExpression;

        rightBranch = parseExpression(currentState.right());

        if(rightBranch.isValid())
        {
            newExpression.setValue((currentState.operation())( expression.value(), rightBranch.value()));
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

    switch (currentToken().type()) {
    case Token::Type::Digit:
      branch.setValue(currentToken().value());
      nextToken();
      break;

    case Token::Type::Root:
    case Token::Type::Power:
      branch = parseFunction();
			nextToken();
      break;

    default:
      break;
    }

    return branch;
}

Node Parser::parseFunction()
{
	Token::Type functionType = currentToken().type();
	int count = parameterCount(functionType);

  std::vector<Node> parameters(count);

  parseFunctionCall(parameters);

	if (currentToken().type() != Token::Type::RightBracket)
	{
		return Node();
	}

	return callFunction(functionType, parameters);
}

void Parser::parseFunctionCall(std::vector<Node>& parameters)
{
  nextToken();
  if(currentToken().type() != Token::Type::LeftBracket)
  {
    return;
  }

  for(auto& parameter : parameters)
  {
		nextToken();

    parameter = parseExpression();

    if(!parameter.isValid())
    {
      return;
    }
    else if(currentToken().type() == Token::Type::Comma)
    {
      continue;
    }
  }
}

bool Parser::updateState(State& state) const
{
    switch (currentToken().type()) {
    case Token::Type::Add:
        state.set(State::Level::level07, State::Level::level08,
                         [](double left, double right) { return left + right;});
        break;

    case Token::Type::Substract:
        state.set(State::Level::level07, State::Level::level08,
                         [](double left, double right) { return left - right;});
        break;

    case Token::Type::Multiply:
        state.set(State::Level::level10, State::Level::level11,
                         [](double left, double right) { return left * right;});
        break;

    case Token::Type::Divide:
        state.set(State::Level::level10, State::Level::level11,
                         [](double left, double right) { return left / right;});
        break;

    case Token::Type::Modulo:
        state.set(State::Level::level10, State::Level::level11,
                  [](double left, double right)
        {
            double intpart;
            if(std::modf(left, &intpart) != 0.0)
                return std::nan("1");

            if(std::modf(right, &intpart) != 0.0)
                return std::nan("1");

            return (double)((long)left % (long)right);
        });

        break;

    default:
        return false;
        break;
    }

    return true;
}

Node Parser::callFunction(Token::Type functionType, const std::vector<Node>& parameters)
{
  Node function;

	switch (functionType) {
  case Token::Type::Root:
    function.setValue(pow(parameters[0].value(), 1 / parameters[1].value()));
    break;

  case Token::Type::Power:
    function.setValue(pow(parameters[0].value(), parameters[1].value()));
    break;
  }

  return function;
}

int Parser::parameterCount(Token::Type functionType) const
{
	switch (functionType) {
  case Token::Type::Root:
  case Token::Type::Power:
    return 2;
    break;

  default:
    break;
  }

  return -1;
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


