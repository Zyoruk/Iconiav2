#include <iostream>

using namespace std;
#include "src/dataStructures/SimpleList/Node/SimpleListNode.h"
#include "src/dataStructures/Tree/binarytreenode.h"
#include "src/dataStructures/Tree/binarytree.h"
int main()
{
    SimpleListNode* node = new SimpleListNode();
    node->setElement(98);
    cout << *(node->getElement()) << "\n";

    BinaryTreeNode* node2 = new BinaryTreeNode();
    node2->setElement(898);
    cout << *(node2->getElement()) << "\n";

    BinaryTreeNode* rightNode = new BinaryTreeNode();
    rightNode->setElement(76);
    node2->setRight(rightNode);
    cout << *(node2->getRight()->getElement()) << "\n";

    cout << "Test tree\n";
    BinaryTree* newTree = new BinaryTree();
    newTree->add(90);
    newTree->add(98);
    newTree->add(89);
    newTree->add(89);

    cout << "trying to remove \n";
    bool test = newTree->remove(90);
    cout << test << "\n";

    test = newTree->remove(89);
    cout << test << "\n";
    return 0;
}
