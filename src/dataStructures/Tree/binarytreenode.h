#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
#include "src/dataStructures/interfaceNode.h"
class BinaryTreeNode :public interfaceNode
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
    interfaceNode* _right;
    interfaceNode* _left;
    interfaceNode* _father;
};

#endif // BINARYTREENODE_H
