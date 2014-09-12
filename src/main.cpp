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
    newTree->add(50);
    newTree->add(48);
    newTree->add(51);
    newTree->add(47);
    newTree->add(60);
    newTree->add(99);
    newTree->add(0);
    cout << newTree->getLenght() << "\n";

    cout << "Lowest fo the high elements"<<*newTree->lowestHighest(newTree->_root)->getElement()<< "\n";
    cout << "Highest if the low elements " << *newTree->highestLowest(newTree->_root)->getElement()<< "\n";;
    cout << newTree->ifExists(98) << "\n";
    cout << newTree->ifExists(0) << "\n";
    cout << newTree->ifExists(-98) << "\n";
}

