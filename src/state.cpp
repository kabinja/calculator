#include "state.h"

State::State():
    m_left(Level::level00),
    m_right(Level::level00)
{
}

void State::set(Level left, Level right, std::function<double(double,double)> operation)
{
    m_left = left;
    m_right = right;
    m_operation = operation;
}

State::Level State::left() const
{
    return m_left;
}

State::Level State::right() const
{
    return m_right;
}

std::function<double(double,double)> State::operation() const
{
    return m_operation;
}
