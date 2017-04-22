#include "parser.h"

Parser::Parser()
{

}

std::string Parser::expression() const
{
    return m_expression;
}

void Parser::append(std::string operation)
{
    m_expression += operation;
}
