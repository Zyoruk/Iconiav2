#include <iostream>

using namespace std;
#include "src/dataStructures/SimpleList/Node/SimpleListNode.h"
int main()
{
    Node* newSLNode = new Node();
    newSLNode = (SimpleListNode*) newSLNode;
    newSLNode->setElement(56);
    int temp = newSLNode->getElement();
    cout << temp << "\n";

    return 0;
}

