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
    void setFather(BinaryTreeNode* pFather);
    BinaryTreeNode* getLeft();
    BinaryTreeNode* getRight();
    BinaryTreeNode* getFather();
private:
    Node* _right;
    Node* _left;
    Node* _father;
};

#endif // BINARYTREENODE_H
