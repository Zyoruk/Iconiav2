#include "interfaceNode.h"
#include <cstddef>
interfaceNode::interfaceNode(){
    this->_element = NULL;
}
interfaceNode::~interfaceNode(){}

void interfaceNode::setElement(int pElement)
{
 this->_element = pElement;
}

int* interfaceNode::getElement(){ return &(this->_element); }

