#ifndef STATE_H
#define STATE_H

class Node;

class State
{
public:

    enum class Level{
        level00,
        level01,
        level02,
        level03,
        level04,
        level05,
        level06,
        level07,
        level08,
        level09,
        level10
    };

protected:

    Level m_left;
    Level m_right;
    std::function<double(double,double)> m_operation;

public:

    State();

    void set(Level left, Level right, std::function<double(double,double)> operation);

    Level left() const;
    Level right() const;
    std::function<double(double,double)> operation() const;
};

#endif // STATE_H
