#include "SimpleListNode.h"
#include <cstddef>

template <typename K>
SimpleListNode<K>::SimpleListNode() {
    Instantiations::Instantiate();
    this->_element = 0;
}

template <typename K>
SimpleListNode<K>::~SimpleListNode() {
    // TODO Auto-generated destructor stub
}
template <typename K>
void SimpleListNode<K>::setElement(K pElement){this->_element = pElement;}

template <typename K>
K* SimpleListNode<K>::getElement(){return &(this->_element);}

template <typename K>
void SimpleListNode<K>::setNext(SimpleListNode<K> *pNextNode){this->_next = pNextNode;}

template <typename K>
SimpleListNode<K>* SimpleListNode<K>::getNext(){return (SimpleListNode<K>*)this->_next;}

template <typename K>
void SimpleListNode<K>::setPrevious(SimpleListNode<K>* pNextNode){this->_next = pNextNode;}

template <typename K>
SimpleListNode<K>* SimpleListNode<K>::getPrevious(){return (SimpleListNode<K>*)this->_previous;}
