#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "token.h"

class Tokenizer
{
protected:

    std::vector<Token> m_tokens;

    std::vector<Token>::const_iterator m_current;

protected:

		std::string charToString(char c) const;

public:
    Tokenizer();

    bool operator==(const Tokenizer& other) const;

    std::string expression() const;
    bool isEmpty() const;
		bool isEnd() const;

		bool tokenize(const std::string& s);
		bool append(std::string operation);
    void pop();
    void clear();

    Token peek() const;
    void next();
    void reset();
};

#endif // TOKENIZER_H
