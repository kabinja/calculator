#ifndef NODE_H
#define NODE_H


class Node
{   
protected:

    enum class State{
        Error,
        Number
    };

    State m_state;
    double m_value;

public:
    Node();

    double value() const;
    bool isValid() const;

    void setValue(double value);
};

#endif // NODE_H
