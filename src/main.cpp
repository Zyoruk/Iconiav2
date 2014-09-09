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

    BinaryTree* myTree = new BinaryTree();
    cout << myTree;
    myTree->add(98);
    myTree->add(100);

    bool toKnow = *(myTree->search(98)->getElement()) == 98;
    cout << toKnow;
    int* searchedNode = myTree->search(98)->getElement();

    cout << *(searchedNode) << "\n";
    return 0;
}
