#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "binarytreenode.h"
class BinaryTree
{
public:
    BinaryTree();
    bool add(int pElement);
    bool remove(int pElement);
    BinaryTreeNode* search(int pElement);
private:
    BinaryTreeNode* _root;
    BinaryTreeNode* searchAux(int pElement, BinaryTreeNode* pLeaf);
    bool addAux(int pElement , BinaryTreeNode* pLeaf);
    bool removeAux ( int pElement , BinaryTreeNode* pLeaf);
    BinaryTreeNode* lowestHigher (BinaryTreeNode* pnode);
};

#endif // BINARYTREE_H
