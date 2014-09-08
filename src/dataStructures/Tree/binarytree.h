#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "binarytreenode.h"
class BinaryTree
{
public:
    BinaryTree();
    bool add(int pElement);
    bool remove(int pElement);
    BinaryTreeNode search(int pElement);
private:
    BinaryTreeNode _root;
};

#endif // BINARYTREE_H
