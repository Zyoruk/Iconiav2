#ifndef GRAPH_H
#define GRAPH_H
#include "src/dataStructures/Graph/graphNode/graphnode.h"
#include "src/dataStructures/SimpleList/SimpleList.h"

template <typename K>

class Graph{
public:
    Graph();
    bool add (K pNode);
    bool remove(K pNode);
    bool exists(K pNode);
    bool connect(K pNodeA , K pNodeB);
    bool areConnected(K pNodeA, K pNodeB);
private:
    SimpleList<GraphNode<K> >* _GraphNodes;
};
template <typename K>
Graph<K>::Graph(){
    this->_GraphNodes = new SimpleList<GraphNode<K> >();
}

template <typename K>
bool Graph<K>::add(K pNode){
    SimpleListNode<GraphNode<K> >* temp = this->_GraphNodes->getHead();
    unsigned int i = 0;
    while (i!=this->_GraphNodes->getLenght()){
        if (*(*temp->getElement()->getElement()) == pNode){
            return false;
        }else{
            temp = temp->getNext();
        }
    }
    GraphNode<K>* newNode = new GraphNode<K>();
    newNode->setElement(pNode);
    this->_GraphNodes->append(newNode);
    return true;
}

template <typename K>
bool Graph<K>::remove(K pNode){
    SimpleListNode<GraphNode<K> >* temp = this->_GraphNodes->getHead();
    unsigned int i = 0;
    while (i != this->_GraphNodes->getLenght()){
        if (*(*temp->getElement()->getElement()) == pNode){
            this->_GraphNodes->remove(temp);
            //falta algo
            return true;
        }else{
            temp = temp->getNext();
        }
    }
    return false;
}

template <typename K>
bool Graph<K>::areConnected(K pNodeA, K pNodeB){
    SimpleListNode<GraphNode<K> >* temA = this->_GraphNodes->getHead();
    unsigned int i = 0;
    while(i != this->_GraphNodes->getLenght()){
        if (*temA->getElement()->getElement() == pNodeA){
            break;
        }else{
            temA = temA->getNext();
        }
    }
    i = 0;
    SimpleListNode<GraphNode<K> >* temB = this->_GraphNodes->getHead();
    while (i != this->_GraphNodes->getLenght()){
        if (*(temB->getElement()->getElement()) == pNodeB){
            break;
        }else{
            temB = temB->getNext();
        }
    }
    // At this point we have 2 values for temA and temB, so we have to ensure those are the correct values

    if (*temA->getElement()->getElement()== pNodeA && *temB->getElement()->getElement() == pNodeB){
        return temA->getElement()->existsConnection(temB->getElement());
    }else{
        return false;
    }
}

template <typename K>
bool Graph<K>::connect(K pNodeA, K pNodeB){
    SimpleListNode<GraphNode<K> >* temA = this->_GraphNodes->getHead();
    unsigned int i = 0;
    while(i != this->_GraphNodes->getLenght()){
        if (*temA->getElement()->getElement() == pNodeA){
            break;
        }else{
            temA = temA->getNext();
        }
    }
    i = 0;
    SimpleListNode<GraphNode<K> >* temB = this->_GraphNodes->getHead();
    while (i != this->_GraphNodes->getLenght()){
        if (*(temB->getElement()->getElement()) == pNodeB){
            break;
        }else{
            temB = temB->getNext();
        }
    }
    // At this point we have 2 values for temA and temB, so we have to ensure those are the correct values

    if (*temA->getElement()->getElement()== pNodeA && *temB->getElement()->getElement() == pNodeB){
        if (temA->getElement()->existsConnection(temB->getElement())){
            return false;
        }else{
            temA->getElement()->connectTo(temB->getElement());
            return true;
        }
    }else{
        return false;
    }
}

template <typename K>
bool Graph<K>::exists(K pNode){
    SimpleListNode<GraphNode<K> >* temp = this->_GraphNodes->getHead();
    unsigned int i = 0;
    while(i != this->_GraphNodes->getLenght()){
        if (*temp->getElement()->getElement() == pNode){
            return true;
        }else{
            temp = temp->getNext();
        }
    }
    return false;
}

#endif // GRAPH_H
