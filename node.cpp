#include "node.h"

Node::Node()
    :m_state(State::Error),
     m_value(std::numeric_limits<double>::quiet_NaN())
{

}

double Node::value() const
{
    return m_value;
}

bool Node::isValid() const
{
    return true;
}

void Node::set(double value)
{
    m_value = value;
}
