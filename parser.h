#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "tokenizer.h"

class Parser
{
protected:

    Tokenizer m_tokenizer;

    std::string m_answer;

public:
    Parser();

    std::string expression() const;

    void addToken(std::string s);
    void removeToken();
    void clearExpression();

    bool evaluate();
};

#endif // PARSER_H
