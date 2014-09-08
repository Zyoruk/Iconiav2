#include "Node.h"
#include <cstddef>
Node::Node(){
    this->_element = 0;
}
Node::~Node(){}

void Node::setElement(int pElement)
{
 this->_element = pElement;
}

int* Node::getElement(){ return &(this->_element); }

