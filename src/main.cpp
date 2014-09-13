#include <iostream>

using namespace std;
#include "src/dataStructures/SimpleList/Node/SimpleListNode.h"
#include "src/dataStructures/Tree/binarytreenode.h"
#include "src/dataStructures/Tree/binarytree.h"
int main()
{
    SimpleListNode<int>* node = new SimpleListNode<int>();
    node->setElement(98);
    cout << *(node->getElement()) << "\n";

    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>();
    node2->setElement(898);
    cout << *(node2->getElement()) << "\n";

    BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>();
    rightNode->setElement(76);
    node2->setRight(rightNode);
    cout << *(node2->getRight()->getElement()) << "\n";

    cout << "Test tree\n";
    BinaryTree<int>* newTree = new BinaryTree<int>();
    cout <<"Adding  [ 50 , 48 , 51 , 47 , 60 , 99 , 0 98 ] ...\n...\n";
    newTree->add(50);
    newTree->add(48);
    newTree->add(51);
    newTree->add(47);
    newTree->add(60);
    newTree->add(99);
    newTree->add(0);
    newTree->add(98);
    cout << newTree->getLenght() << " Current lenght of tree \n";
    cout << newTree->ifExists(98) << " Searched 98 \n";
    cout << newTree->ifExists(0) << " Searched 0 \n";
    cout << newTree->ifExists(-98) << " Searched -98\n";
    cout << "Deleting 98 ...\n";
    newTree->remove(98);
    cout << newTree->ifExists(98) << " Searched 98 \n";
    cout << newTree->getLenght() << " Current lenght of tree \n";
    cout << newTree->ifExists(50) << " Searched 50 \n";
    cout << "Deleting 50 ...\n";
    newTree->remove(50);
    cout << newTree->ifExists(50) << " Searched 50 \n";
    cout << newTree->getLenght() << " Current lenght of tree \n";
}

