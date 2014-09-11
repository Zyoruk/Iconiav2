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
    bool ifExists(int pElement);
    unsigned int getLenght();
private:
    BinaryTreeNode* _root;
    unsigned int lenght;
    BinaryTreeNode* searchAux(int pElement, BinaryTreeNode* pLeaf);
    bool addAux(int pElement , BinaryTreeNode* pLeaf);
    bool removeAux ( int pElement , BinaryTreeNode* pLeaf);
    BinaryTreeNode* lowestHighest (BinaryTreeNode* pNode);
};
#endif // BINARYTREE_H
