    #include "SimpleListNode.h"
#include <cstddef>

SimpleListNode::SimpleListNode() {
    this->_element = 0;
}
SimpleListNode::~SimpleListNode() {
    // TODO Auto-generated destructor stub
}

void SimpleListNode::setElement(int pElement){this->_element = pElement;}
int* SimpleListNode::getElement(){return &(this->_element);}

void SimpleListNode::setNext(SimpleListNode *pNextNode){this->_next = pNextNode;}
SimpleListNode* SimpleListNode::getNext(){return (SimpleListNode*)this->_next;}

void SimpleListNode::setPrevious(SimpleListNode* pNextNode){this->_next = pNextNode;}
SimpleListNode* SimpleListNode::getPrevious(){return (SimpleListNode*)this->_previous;}



