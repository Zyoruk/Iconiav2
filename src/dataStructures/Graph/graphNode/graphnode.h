#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include "src/dataStructures/interfaceNode.h"
#include "src/dataStructures/SimpleList/SimpleList.h"
template <typename K>
class GraphNode: public interfaceNode<K>{
public:
    GraphNode();
    bool existsConnection(GraphNode* pNodeTo);
    bool removeConnectionTo(GraphNode* pNodeTo);
    bool connectTo(GraphNode* pNodeTo);
private:
    SimpleList<GraphNode*>* _connectedTo;
};
template <typename K>
GraphNode<K>::GraphNode(){
    this->_connectedTo = new SimpleList<GraphNode*>();
}
template <typename K>
bool GraphNode<K>::existsConnection(GraphNode *pNodeTo){
    return this->_connectedTo->ifExists(pNodeTo);
}

template <typename K>
bool GraphNode<K>::connectTo(GraphNode *pNodeTo){
   return this->_connectedTo->append(pNodeTo);
}
template <typename K>
bool GraphNode<K>::removeConnectionTo(GraphNode *pNodeTo){
    return this->_connectedTo->remove(pNodeTo);
}

#endif // GRAPHNODE_H
