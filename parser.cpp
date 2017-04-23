#include "parser.h"

Parser::Parser()
{

}

std::string Parser::expression() const
{
    return m_current.expression();
}

std::string Parser::answer() const
{
    return m_answer;
}

void Parser::addToken(std::string s)
{
    m_current.append(s);
}

void Parser::removeToken()
{
    m_current.pop();
}

void Parser::clearExpression()
{
    m_current.clear();
}

bool Parser::evaluate()
{
    if(m_current == m_last)
        return false;

    if(m_current.isEmpty())
    {
        m_answer.clear();
    }
    else
    {
        m_answer = "resut = " + m_current.expression();
    }

    m_last = m_current;

    return true;
}
