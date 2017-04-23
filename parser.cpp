#include "parser.h"

Parser::Parser()
{

}

std::string Parser::expression() const
{
    return m_tokenizer.expression();
}

void Parser::addToken(std::string s)
{
    m_tokenizer.append(s);
}

void Parser::removeToken()
{
    m_tokenizer.pop();
}

void Parser::clearExpression()
{
    m_tokenizer.clear();
}

bool Parser::evaluate()
{
    return false;
}
