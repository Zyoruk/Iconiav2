#ifndef SIMPLELIST_H
#define SIMPLELIST_H
#include"src/dataStructures/SimpleList/Node/SimpleListNode.h"

template <typename K>
class SimpleList{
public:
    SimpleList();
    unsigned int getLenght();
    bool append (K pElement);
    bool remove (K pElement);
    bool ifExists (K pElement);
    bool isEmpty();
    bool removeAt (int pIndex);
    SimpleListNode<K>* search(K pElement);
    SimpleListNode<K>* getHead();
    SimpleListNode<K>* getTail();
    SimpleListNode<K>* elementAt(int pIndex);
    int indexOf(K pElement);

private:
    unsigned int _lenght;
    SimpleListNode<K>* _head;
    SimpleListNode<K>* _tail;
};

template <typename K> SimpleList<K>::SimpleList(){
    this->_head = 0 ;
    this->_lenght= 0;
    this->_tail = 0;
}


template <typename K>
bool SimpleList<K>::isEmpty(){ return this->_lenght == 0;}

template <typename K>
unsigned int SimpleList<K>::getLenght(){return this->_lenght;}

template <typename K>
SimpleListNode<K>* SimpleList<K>::getHead(){return this->_head;}

template <typename K>
SimpleListNode<K>* SimpleList<K>::getTail(){return this->_tail;}

template <typename K>
SimpleListNode<K>* SimpleList<K>::search(K pElement){
    if (this->_lenght == 0){
        return 0;
    }else{
        SimpleListNode<K>* current = this->_head;
        for ( int i = 0 ; i < this->_lenght ; i++){
            if (*(current->getElement()) == pElement){
                return current;
            }else{
                if ( current->getNext() == 0){
                    return 0;
                }
                current = current->getNext();
            }
        }
        return 0;
    }
}

template <typename K>
bool SimpleList<K>::ifExists(K pElement){
    if (this->_lenght == 0){
        return false;
    }
    SimpleListNode<K>* current = this->_head;
    for ( int i = 0 ; i < this->_lenght ; i++){
        if (*(current->getElement()) == pElement){
            return true;
        }else{
            if ( current->getNext() == 0){
                return false;
            }
            current = current->getNext();
        }
    }
    return false;
}

template <typename K>
bool SimpleList<K>::append(K pElement){
    if (this->_lenght == 0){
        SimpleListNode<K>* tmp = new SimpleListNode<K>();
        tmp->setElement(pElement);
        this->_head = tmp;
        this->_tail = this->_head;
        this->_lenght += 1;
        return true;
    }else{
        SimpleListNode<K>* tmp = new SimpleListNode<K>();
        tmp->setElement(pElement);
        this->getTail()->setNext(tmp);
        this->_tail = tmp;
        this->_lenght += 1;
        return true;
    }
    return false;
}

template <typename K>
bool SimpleList<K>::remove(K pElement){
    if (this->_lenght == 0){
        return false;
    }else{
        SimpleListNode<K>* current = this->_head;
        for ( int i = 0 ; i < this->_lenght ; i++){
            if (*this->_head->getElement() == pElement){
                if (this->_head->getNext() == 0){
                    this->_head = 0;
                    this->_lenght -=1;
                    return true;
                }else{
                    this->_head = this->_head->getNext();
                    this->_lenght -=1;
                    return true;
                }
            }else if (current->getNext()->getNext() == 0){
                if (*current->getNext()->getElement() == pElement){
                    SimpleListNode<K>* tmp = current->getNext()->getNext();
                    current->getNext()->setNext(0);
                    current->setNext(tmp);
                    this->_lenght -=1;
                    return true;
                }
                return false;
            }else{
                if (*current->getNext()->getElement() == pElement){
                    SimpleListNode<K>* tmp = current->getNext()->getNext();
                    current->getNext()->setNext(0);
                    current->setNext(tmp);
                    this->_lenght -=1;
                    this->_tail = tmp;
                    return true;
                }else{
                    current = current->getNext();
                }
            }
        }
        return false;
    }
}

template <typename K>
SimpleListNode<K>* SimpleList<K>::elementAt(int pIndex){
    if (this->_lenght == 0){
        return 0;
    }else if (pIndex > this->_lenght -1){
        return 0;
    }else{
        SimpleListNode<K>* current = this->_head;
        for ( int i = 0 ; i < this->_lenght ; i++){
            if (i == pIndex){
                return current;
            }else{
                if ( current->getNext() == 0){
                    return 0;
                }
                current = current->getNext();
            }
        }
        return 0;
    }
}

template <typename K>
int SimpleList<K>::indexOf(K pElement){
    if (this->_lenght == 0){
        return -1;
    }else{
        SimpleListNode<K>* current = this->_head;
        for ( int i = 0 ; i < this->_lenght ; i++){
            if (*(current->getElement()) == pElement){
                return i;
            }else{
                if ( current->getNext() == 0){
                    return -1;
                }
                current = current->getNext();
            }
        }
        return -1;
    }
}

template <typename K>
bool SimpleList<K>::removeAt (int pIndex){
    if (this->_lenght == 0){
        return false;
    }else{
        if (pIndex >= this->_lenght){
            return false;
        }
        SimpleListNode<K>* current = this->_head;
        SimpleListNode<K>* previous = 0;
        int i = 0;
        while (i != pIndex){
            if  (current->getNext() == 0 ){
                this->_tail = previous;
                current = 0;
                return true;
            }
            current = current->getNext();
            previous = current;
        }
        if (current->getNext()->getNext() == 0){
            this->_tail = previous;
            current = 0;
            return true;
        }
        previous->setNext(current->getNext()->getNext());
        current->setElement(0);
        current = 0;
        return true;
    }
}


#endif // SIMPLELIST_H
