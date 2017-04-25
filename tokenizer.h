#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "token.h"

class Tokenizer
{
protected:

    std::vector<Token> m_tokens;

    std::vector<Token>::const_iterator m_current;

public:
    Tokenizer();

    bool operator==(const Tokenizer& other) const;

    std::string expression() const;
    bool isEmpty() const;

    void append(std::string operation);
    void pop();
    void clear();

    Token peek() const;
    void next();
    void reset();
};

#endif // TOKENIZER_H
