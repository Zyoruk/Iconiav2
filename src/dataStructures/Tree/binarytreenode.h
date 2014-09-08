#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
#include "src/dataStructures/Node.h"
class BinaryTreeNode :public Node
{
public:
    BinaryTreeNode();
    int* getElement();
    void setElement(int pElement);
    void setRight(BinaryTreeNode* pRight);
    void setLeft(BinaryTreeNode* pLeft);
    BinaryTreeNode* getLeft();
    BinaryTreeNode* getRight();
private:
    Node* _right;
    Node* _left;
};

#endif // BINARYTREENODE_H
