#ifndef PARSER_H
#define PARSER_H

#include <string>

class Parser
{
protected:

    std::string m_expression;
    std::string m_last;

public:
    Parser();

    std::string expression() const;

    void append(std::string operation);
};

#endif // PARSER_H
