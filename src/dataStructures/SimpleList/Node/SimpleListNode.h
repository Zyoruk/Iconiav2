#ifndef SIMPLELISTNODE_H
#define SIMPLELISTNODE_H
#include "src/dataStructures/Node.h"
class SimpleListNode: public Node {
public:
    SimpleListNode();
    virtual ~SimpleListNode();
    void setNext(SimpleListNode pNextNode);
    Node getNext();
private:
    Node _next;
};

#endif // SIMPLELISTNODE_H

