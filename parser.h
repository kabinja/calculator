#ifndef PARSER_H
#define PARSER_H

#include "tokenizer.h"

class Parser
{
protected:

    Tokenizer m_current;
    Tokenizer m_last;

    std::string m_answer;

public:
    Parser();

    std::string expression() const;
    std::string answer() const;

    void addToken(std::string s);
    void removeToken();
    void clearExpression();

    bool evaluate();
};

#endif // PARSER_H
