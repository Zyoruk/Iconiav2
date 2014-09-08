#include "simplelist.h"
#include <src/dataStructures/SimpleList/Node/SimpleListNode.h>
#include <cstddef>
SimpleList::SimpleList()
{
    this->_head = new SimpleListNode();
    this->_tail = _head;
    this->_previous = NULL;
    this->_lenght = 0;
}
bool SimpleList::search(int pElement){
    if (this->_lenght == 0){
        return false;
    }else{
        SimpleListNode * _current = _head;
        unsigned int i = 0;
        while (_current->getElement() != pElement){
            int currentElement = _current->getNext().getElement();
            _current= new SimpleListNode();
            _current->setElement(currentElement);
            if (i == this->_lenght){
                return false;
            };
        }
        return true;
    };
}
SimpleListNode SimpleList::getNode(int pElement){
    if (this->_lenght == 0){
        return NULL;
    }else{
        SimpleListNode * _current = _head;
        unsigned int i = 0;
        while (_current->getElement() != pElement){
            int currentElement = _current->getNext().getElement();
            _current= new SimpleListNode();
            _current->setElement(currentElement);
            if (i == this->_lenght){
                return NULL;
            };
        }
        return _current;
    }
}

bool SimpleList::append(int pElement){
    if (this->_lenght == 0){
        this->_head->setElement(pElement);
        this->_tail = this->_head;
    }else if (this->search(pElement) == true){
        return false;
    }else{
        this->_previous = this->_tail;
        this->_tail->setNext(pElement);
        this->_tail = this->_tail->getNext();
    }
}

bool SimpleList::remove(int pElement){
    if(this->_lenght == 0){
        return false;
    }else if (this->search(pElement) == true){
        SimpleListNode _nodeToRemove = this->getNode(pElement);
        _nodeToRemove
}
