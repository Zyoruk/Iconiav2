#include "binarytreenode.h"
#include <cstddef>

BinaryTreeNode::BinaryTreeNode()
{
    this->setElement(NULL);
}
int* BinaryTreeNode::getElement(){
    return &this->_element;
}

void BinaryTreeNode::setElement(int pElement){
    this->_element = pElement;
}

BinaryTreeNode* BinaryTreeNode::getLeft(){
    return (BinaryTreeNode*)this->_left;
}

BinaryTreeNode* BinaryTreeNode::getRight(){
    return (BinaryTreeNode*)this->_right;
}

void BinaryTreeNode::setLeft(BinaryTreeNode *pLeft){
    this->_left = pLeft;
}
void BinaryTreeNode::setRight(BinaryTreeNode *pRight){
    this->_right = pRight;
}

