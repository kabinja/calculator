#include "tokenizer.h"

std::string Tokenizer::charToString(char c) const
{
	std::stringstream ss;
	std::string s;
	ss << c;
	ss >> s;

	return s;
}

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

bool Tokenizer::tokenize(const std::string& s)
{
	bool alpha = false, error = false;
  std::string operation;

  for(auto c : s)
  {
		if(error)
		{
			break;
		}

		if(std::isspace(c))
		{
			if(!operation.empty())
			{
				append(operation);
				operation.clear();
			}

			alpha = false;
		}
		else if(std::isalpha(c))
		{
			if(!alpha && !operation.empty())
			{
				error |= append(operation);
				operation.clear();
			}

			alpha = true;
			operation += c;
		}
		else if(std::isdigit(c))
		{
			if(alpha)
			{
				operation += c;
			}
			else
			{
				operation.empty();
				error |= append(s);
			}
		}
		else
		{
			if(!operation.empty())
			{
				error |= append(operation);
				operation.clear();
			}

			alpha = false;

			error |= append(charToString(c));
		}
	}

	return !error;
}

bool Tokenizer::append(std::string operation)
{
    Token token = Token::fromString(operation);

    if(token.isError())
				return false;

    if(!m_tokens.empty())
    {
        if(m_tokens.back().append(token))
						return true;

        if(token.isDigit() && m_tokens.back().isDigit())
						return false;
    }

   m_tokens.push_back(token);

	 return true;
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
