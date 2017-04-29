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
    Node parseBranch();
    Node parseFunction();
    bool parseFunctionCall(std::vector<Node>& parameters);

    bool updateState(State& state) const;
    Node callFunction(Token::Type functionType, const std::vector<Node>& paramaters);
    int parameterCount(Token::Type functionType) const;

public:
    Parser();

    std::string answer() const;

		void evaluate(Tokenizer tokens);
		void clear();
};

#endif // PARSER_H
