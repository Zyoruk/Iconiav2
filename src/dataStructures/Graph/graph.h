#ifndef GRAPH_H
#define GRAPH_H
#include "src/dataStructures/Graph/graphNode/graphnode.h"
#include "src/dataStructures/SimpleList/SimpleList.h"

template <typename K>

class Graph{
public:
    bool add (GraphNode* pNode);
    bool remove(GraphNode* pNode);
    bool exists(GraphNode* pNode);
    bool connect(GraphNode* pNodeA , GraphNode* pNodeB);
    bool areConnected(GraphNode* pNodeA, GraphNode* pNodeB);
private:
    SimpleList<GraphNode*>* _GraphNodes;
};

bool Graph<K>::add(GraphNode pNode){
    if (this->_GraphNodes->ifExists(pNode)){

    }
}

#endif // GRAPH_H
