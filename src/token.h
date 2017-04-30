#ifndef TOKEN_H
#define TOKEN_H

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
        Modulo,
				Sqrt,
        Power,
        LeftBracket,
        RightBracket,
        Comma
    };

protected:

    Type m_type;
    std::string m_value;

public:
    Token();

    bool operator==(const Token& other) const;

    double value() const;
    Token::Type type() const;

    bool isError() const;
    bool isDigit() const;
    bool isSameType(const Token& token) const;

    std::string toString() const;

    bool append(const Token& token);
    bool pop();

    static Token fromString(std::string s);
};

#endif // TOKEN_H
