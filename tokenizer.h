#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "token.h"

class Tokenizer
{
protected:

    std::vector<Token> m_tokens;

public:
    Tokenizer();

    bool operator==(const Tokenizer& other) const;

    std::string expression() const;
    bool isEmpty() const;

    void append(std::string operation);
    void pop();
    void clear();
};

#endif // TOKENIZER_H
