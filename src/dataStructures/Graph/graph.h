#ifndef GRAPH_H
#define GRAPH_H
#include "src/dataStructures/Graph/graphNode/graphnode.h"
#include "src/dataStructures/SimpleList/SimpleList.h"
#include "iostream"

template <typename K>

class Graph{
public:
    Graph();
    /*!
     * \brief add is going to create a new node to the graph.
     * \param pNode which is the element of the node we want to add.
     * \return boolean depending if it was able to add.
     */
    bool add (K pNode);
    /*!
     * \brief remove is going to delete a node that contains the element
     * \param pNode is the element of the node we want to remove.
     * \return boolean if it was able.
     */
    bool remove(K pNode);
    /*!
     * \brief exists searches for  the node containing the element
     * \param pNode is the element contained
     * \return boolean if it was able
     */
    bool exists(K pNode);
    /*!
     * \brief connect will connect the two nodes that contains A and B.
     * \param pNodeA element of the node.
     * \param pNodeB element of the node.
     * \return boolean if it was able to connect, the only way it wouldn't is if the connection already exists. Or that one node doesn't exist.
     */
    bool connect(K pNodeA , K pNodeB);
    /*!
     * \brief areConnected search if the two nodes are connected.
     * \param pNodeA element of the node.
     * \param pNodeB element of the node.
     * \return boolean if the nodes were connected.
     */
    bool areConnected(K pNodeA, K pNodeB);
    /*!
     * \brief describe will print every node of the graph.
     */
    void describe();

    bool clear();
private:
    /*!
     * \brief _GraphNodes simple linked list containing the pointers to the nodes.
     */
    SimpleList<GraphNode<K>* >* _GraphNodes;
    /*!
     * \brief _elements simple linked list containing only the elements of every node.
     */
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
    return this->_elements->ifExists(pNode);
}

template< typename K>
void Graph<K>::describe(){
    SimpleListNode<K>* temp = this->_elements->getHead();
    int i = 0;
    while (i!=this->_elements->getLenght()){
        cout << *temp->getElement()<< " ";
        temp = temp->getNext();
        i++;
    }
}
template <typename K>
bool Graph<K>::clear(){
    this->_elements->clear();
    this->_GraphNodes->clear();
    return true;
}

#endif // GRAPH_H
