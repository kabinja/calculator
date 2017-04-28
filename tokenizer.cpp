#include "tokenizer.h"

Tokenizer::Tokenizer()
{

}

bool Tokenizer::operator==(const Tokenizer& other) const
{
    return m_tokens == other.m_tokens;
}

std::string Tokenizer::expression() const
{
    std::string expression;

    for (auto& token : m_tokens)
        expression += token.toString() + " ";

   expression.erase(std::find_if(expression.rbegin(), expression.rend(),
                std::not1(std::ptr_fun<int, int>(isspace))).base(), expression.end());

   return expression;
}

bool Tokenizer::isEmpty() const
{
    return m_tokens.empty();
}

bool Tokenizer::isEnd() const
{
	if (isEmpty())
	{
		return true;
	}

	return m_current == m_tokens.end();
}

void Tokenizer::append(std::string operation)
{
    Token token = Token::fromString(operation);

    if(token.isError())
        return;

    if(!m_tokens.empty())
    {
        if(m_tokens.back().append(token))
            return;

        if(token.isDigit() && m_tokens.back().isDigit())
            return;
    }

   m_tokens.push_back(token);
}

void Tokenizer::pop()
{
    if(m_tokens.empty())
        return;

    if(m_tokens.back().pop())
        return;

    m_tokens.pop_back();
}

void Tokenizer::clear()
{
    m_tokens.clear();
}

Token Tokenizer::peek() const
{
    if(m_current == m_tokens.end())
        return Token();

    return *m_current;
}

void Tokenizer::next()
{
    if(m_current == m_tokens.end())
        return;

    ++m_current;
}

void Tokenizer::reset()
{
    m_current = m_tokens.begin();
}
