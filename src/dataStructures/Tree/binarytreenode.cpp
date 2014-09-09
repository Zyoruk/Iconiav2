#include "binarytreenode.h"
#include <cstddef>

BinaryTreeNode::BinaryTreeNode()
{
    this->_element = NULL;
    this->_left = NULL;
    this->_right = NULL;
    this->_father = NULL;
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

BinaryTreeNode* BinaryTreeNode::getFather(){
    return (BinaryTreeNode*)this->_father;
}

void BinaryTreeNode::setLeft(BinaryTreeNode *pLeft){
    this->_left = pLeft;
}
void BinaryTreeNode::setRight(BinaryTreeNode *pRight){
    this->_right = pRight;
}

void BinaryTreeNode::setFather(BinaryTreeNode* pFather){
    this->_father = pFather;
}
