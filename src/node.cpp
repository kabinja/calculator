#include "node.h"

Node::Node()
    :m_state(State::Error),
     m_value(std::nan("1"))
{

}

double Node::value() const
{
    return m_value;
}

bool Node::isValid() const
{
    return m_state != State::Error;
}

void Node::setValue(double value)
{
	m_state = std::isnan(value) ? State::Error : State::Number;
	m_value = value;
}
