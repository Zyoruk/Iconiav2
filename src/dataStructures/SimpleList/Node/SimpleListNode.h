#ifndef SIMPLELISTNODE_H
#define SIMPLELISTNODE_H
#include "src/dataStructures/Node.h"
class SimpleListNode: public Node {
public:
    SimpleListNode();
    virtual ~SimpleListNode();
    void setElement(int pElement);
    int* getElement();
    void setNext(SimpleListNode* pNextNode);
    SimpleListNode* getNext();
    void setPrevious(SimpleListNode* pPreviousNode);
    SimpleListNode* getPrevious();
private:
    Node* _next ;
    Node* _previous;
};

#endif // SIMPLELISTNODE_H

