#ifndef CONNECTION_H
#define CONNECTION_H
#include "src/dataStructures/Graph/graphNode/graphnode.h"
class GraphNode;
template <typename K>
class Connection
{
public:
    Connection();
//    Connection(GraphNode<K>* pNodeTo ,GraphNode<K>* pNodeFrom);
    GraphNode* getNodeTo();
    GraphNode* getNodeFrom();
    void setNodeTo(GraphNode* pNodeTo);
    void setNodeFrom(GraphNode* pNodeFrom);
private:
    GraphNode* _nodeTo;
    GraphNode* _nodeFrom;
};
template <typename K>
Connection<K>::Connection(){
    this->_nodeFrom = 0;
    this->_nodeTo = 0;
}
//template <typename K>
//Connection<K>::Connection(GraphNode<K> *pNodeTo, GraphNode<K> *pNodeFrom){
  //  this->_nodeFrom = pNodeFrom;
    //this->_nodeTo = pNodeTo;
//}

template <typename K>
GraphNode* Connection<K>::getNodeFrom(){return this->_nodeFrom;}
template <typename K>
GraphNode* Connection<K>::getNodeTo(){return this->_nodeTo;}
template <typename K>
void Connection<K>::setNodeFrom(GraphNode* pNodeFrom){this->_nodeFrom = pNodeFrom;}
template <typename K>
void Connection<K>::setNodeTo(GraphNode* pNodeTo){this->_nodeTo = pNodeTo;}
#endif // CONNECTION_H
