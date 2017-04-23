#include "tokenizer.h"

Tokenizer::Tokenizer()
{

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
