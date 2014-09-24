#ifndef GRAPH_H
#define GRAPH_H
#include "src/dataStructures/Graph/graphNode/graphnode.h"
#include "src/dataStructures/SimpleList/SimpleList.h"

template <typename K>

class Graph{
public:
    Graph();
    bool add (GraphNode* pNode);
    bool remove(GraphNode* pNode);
    bool exists(GraphNode* pNode);
    bool connect(GraphNode* pNodeA , GraphNode* pNodeB);
    bool areConnected(GraphNode* pNodeA, GraphNode* pNodeB);
private:
    SimpleList<GraphNode*>* _GraphNodes;
    SimpleList<K>* _existantElements;
};

bool Graph::add(GraphNode* pNode){
    if (this->_existantElements->append(*pNode->getElement())){
        return this->_GraphNodes->append(pNode);
    }else{
        return false;
    }
}

bool Graph::remove(GraphNode *pNode){
    if (this->_existantElements->remove(*pNode->getElement())){
        return this->_GraphNodes->remove(pNode);
    }else{
        return false;
    }
}


#endif // GRAPH_H
