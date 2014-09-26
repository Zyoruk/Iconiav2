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
    SimpleList<GraphNode<K>* >* _GraphNodes;
    SimpleList<K>* _elements;
};
template <typename K>
Graph<K>::Graph(){
    this->_GraphNodes = new SimpleList<GraphNode<K>* >();
    this->_elements = new SimpleList<K>();
}
template <typename K>
bool Graph<K>::add(K pNode){
    if (this->_elements->ifExists(pNode)){
        return false;
    }
    GraphNode<K>* newNode = new GraphNode<K>();
    newNode->setElement(pNode);
    this->_elements->append(pNode);
    this->_GraphNodes->append(newNode);
    return true;
}

template <typename K>
bool Graph<K>::remove(K pNode){
    int index = this->_elements->indexOf(pNode);
    if (index == -1){
        return false;
    }
    this->_elements->removeAt(index);
    this->_GraphNodes->removeAt(index);
    return true;
}

template <typename K>
bool Graph<K>::areConnected(K pNodeA, K pNodeB){
    int indexA = this->_elements->indexOf(pNodeA);
    int indexB = this->_elements->indexOf(pNodeB);
    GraphNode<K>* nodeA = (*this->_GraphNodes->elementAt(indexA)->getElement());
    GraphNode<K>* nodeB = (*this->_GraphNodes->elementAt(indexB)->getElement());
    return nodeA->existsConnection(nodeB);
}

template <typename K>
bool Graph<K>::connect(K pNodeA, K pNodeB){
    int indexA = this->_elements->indexOf(pNodeA);
    int indexB = this->_elements->indexOf(pNodeB);
    GraphNode<K>* nodeA = (*this->_GraphNodes->elementAt(indexA)->getElement());
    GraphNode<K>* nodeB = (*this->_GraphNodes->elementAt(indexB)->getElement());
    return nodeA->connectTo(nodeB);
}

template <typename K>
bool Graph<K>::exists(K pNode){
    SimpleListNode<K>* temp = this->_elements->getHead();
    unsigned int i = 0;
    while(i != this->_elements->getLenght()-1){
        if (*temp->getElement()== pNode){
            return true;
        }else{
            temp = temp->getNext();
        }
    }
    return false;
}

#endif // GRAPH_H
