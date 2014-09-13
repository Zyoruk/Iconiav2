#include "interfaceNode.h"
#include <cstddef>
template <typename K>

interfaceNode<K>::interfaceNode(){
    this->_element = 0;
}

template <typename K>
interfaceNode<K>::~interfaceNode(){}

template <typename K>
void interfaceNode<K>::setElement(K pElement)
{
 this->_element = pElement;
}

template <typename K>
K* interfaceNode<K>::getElement(){ return &(this->_element); }

