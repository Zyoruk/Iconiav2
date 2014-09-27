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

    /*!
     * \brief clears empties the graph
     * \return boolean
     */
    bool clear();

    /*!
     * \brief getNode returns the node.
     * \param pNode is the one we want to get
     * \return pointer to the node.
     */
    GraphNode<K>* getNode(K pNode);
    /*!
     * \brief moveAB move from A to B
     * \param nodeA node from where we move
     * \param nodeB node where to move
     * \return boolean if it was able to move from A to B.
     */
    bool moveAB(K nodeA, K nodeB);
private:
    /*!
     * \brief _GraphNodes simple linked list containing the pointers to the nodes.
     */
    SimpleList<GraphNode<K>* >* _GraphNodes;
    /*!
     * \brief _elements simple linked list containing only the elements of every node.
     */
    SimpleList<K>* _elements;

    void searchforPaths (GraphNode<K>* pNodeA , GraphNode<K>* pNodeB, SimpleList<GraphNode<K>* >* pList, SimpleList<GraphNode<K>* >* closed);
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

template <typename K>
GraphNode<K>* Graph<K>::getNode(K pNode){
    int index = this->_elements->indexOf(pNode);
    return *this->_GraphNodes->elementAt(index)->getElement();
}

template <typename K>
bool Graph<K>::moveAB(K nodeA, K nodeB){
    SimpleList <GraphNode<K>* >* possibleSolution = new SimpleList<GraphNode<K>* >();
    int indexA = this->_elements->indexOf(nodeA);
    int indexB = this->_elements->indexOf(nodeB);
    GraphNode<K>* tempA = *this->_GraphNodes->elementAt(indexA)->getElement();
    GraphNode<K>* tempB = *this->_GraphNodes->elementAt(indexB)->getElement();
    SimpleList<GraphNode<K>* >* closed = new SimpleList<GraphNode<K>* >();
    this->searchforPaths(tempA,tempB,possibleSolution,closed);
//    if(possibleSolution->getLenght() == 1){
//        return false;
//    }else if (*(*possibleSolution->getHead()->getElement())->getElement() == nodeA &&
//              *(*possibleSolution->getTail()->getElement())->getElement() == nodeB){
//        return true;
//    }else{
//        return false;
//    }
}
template <typename K>
void Graph<K>::searchforPaths(GraphNode<K> *pNodeA, GraphNode<K> *pNodeB, SimpleList<GraphNode<K> *>* pList, SimpleList<GraphNode<K>* >* closed){
    SimpleList<GraphNode<K>* >* temp = pNodeA->getConnections();
    pList->append(pNodeA);
    cout << " Aqui";
    if (temp->getLenght() != 0){
        if (temp->ifExists(pNodeB)){
            pList->append(pNodeB);
            closed->clear();
            closed = 0;
            temp->clear();
            temp = 0;
        }
    }
//        }else if((*temp->getHead()->getElement())->getConnections()->getLenght() == 0){
//            closed->append(*temp->getHead()->getElement());
//            searchforPaths(pNodeA,pNodeB,pList,closed);
//        }else{
//            searchforPaths(*temp->getHead()->getElement(),pNodeB,pList,closed);
//        }
//    }
}

#endif // GRAPH_H
