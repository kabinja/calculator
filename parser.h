#ifndef PARSER_H
#define PARSER_H

#include "state.h"
#include "node.h"
#include "tokenizer.h"

class Parser
{
protected:

    Tokenizer m_tokens;
    std::string m_answer;

protected:

    Token currentToken() const;
    void nextToken();

    Node parseExpression(State::Level level = State::Level::level00);
    Node parseBranch(State::Level level = State::Level::level00);
    Node parseFunction();
    void parseFunctionCall(std::vector<Node>& parameters);
		Node callFunction(Token::Type functionType, const std::vector<Node>& paramaters);
		int parameterCount(Token::Type functionType) const;

public:
    Parser();

    std::string expression() const;
    std::string answer() const;

    void addToken(std::string s);
    void removeToken();
    void clearExpression();

    void evaluate();
};

#endif // PARSER_H
