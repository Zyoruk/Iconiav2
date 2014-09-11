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
    newTree->add(97);
    newTree->add(234);
    newTree->add(3);
    newTree->add(23);
    newTree->add(54);
    newTree->add(65);
    newTree->add(67);
    newTree->add(78);
    newTree->add(94);
    newTree->add(2);
    newTree->add(0);
    newTree->add(345435);
    newTree->add(234);
    cout << newTree->getLenght() << "\n";
}
