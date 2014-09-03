#include "SimpleListNode.h"
#include <cstddef>

SimpleListNode::SimpleListNode() {
}
SimpleListNode::~SimpleListNode() {
    // TODO Auto-generated destructor stub
}

Node SimpleListNode::getNext(){return this->_next;}

void SimpleListNode::setNext(SimpleListNode pNextNode){this->_next = pNextNode;}


