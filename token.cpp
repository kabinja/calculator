#include "token.h"

Token::Token()
    : m_type(Type::Error)
{
}

bool Token::operator==(const Token& other) const
{
    return m_type == other.m_type && m_value == other.m_value;
}

double Token::value() const
{
    if(!isDigit())
        return std::numeric_limits<double>::quiet_NaN();;

    return ::atof(m_value.c_str());
}

Token::Type Token::type() const
{
    return m_type;
}

bool Token::isError() const
{
    return m_type == Type::Error;
}

bool Token::isDigit() const
{
    return m_type == Type::Digit;
}

bool Token::isSameType(const Token& token) const
{
    return token.m_type == m_type;
}

std::string Token::toString() const
{
    return m_value;
}

bool Token::append(const Token& token)
{
    if(token.m_type != Type::Digit || m_type != Type::Digit)
    {
        return false;
    }

    if(token.m_value == "." && m_value.find(".") != std::string::npos)
    {
        return false;
    }

    m_value += token.m_value;

    return true;
}

bool Token::pop()
{
    if(!isDigit())
        return false;

    if(m_value.size() == 1)
        return false;

    m_value.pop_back();

    return true;
}

Token Token::fromString(std::string s)
{
   Token token;

   std::locale loc;
   if(std::isdigit(s[0], loc) || s == ".")
       token.m_type = Type::Digit;
   else if(s == "+")
       token.m_type = Type::Add;
   else if(s == "-")
       token.m_type = Type::Substract;
   else if(s == "/")
       token.m_type = Type::Divide;
   else if(s == "*")
       token.m_type = Type::Multiply;
   else if(s == "root")
       token.m_type = Type::Root;
   else if(s == "power")
       token.m_type = Type::Power;
   else if(s == "%")
       token.m_type = Type::Modulo;
   else if(s == "(")
       token.m_type = Type::LeftBracket;
	 else if (s == ")")
		 token.m_type = Type::RightBracket;
	 else if (s == ",")
		 token.m_type = Type::Comma;

   token.m_value = s;

   return token;
}
