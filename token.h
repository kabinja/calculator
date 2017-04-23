#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token
{
public:

    enum class Type
    {
        Error,
        Digit,
        Add,
        Substract,
        Multiply,
        Divide,
        Power,
        Root,
        Modulo,
        LeftParenthesis,
        RightParenthesis,
    };

protected:

    Type m_type;
    std::string m_value;

public:
    Token();

    bool isError() const;
    bool isDigit() const;
    bool isSameType(const Token& token) const;

    std::string toString() const;

    bool append(const Token& token);
    bool pop();

    static Token fromString(std::string s);
};

#endif // TOKEN_H
