#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
#include "src/dataStructures/interfaceNode.h"
template <typename K>
class BinaryTreeNode :public interfaceNode<K>
{
public:
    BinaryTreeNode();
    K* getElement();
    void setElement(K pElement);
    void setRight(BinaryTreeNode* pRight);
    void setLeft(BinaryTreeNode* pLeft);
    void setFather(BinaryTreeNode* pFather);
    BinaryTreeNode* getLeft();
    BinaryTreeNode* getRight();
    BinaryTreeNode* getFather();
private:
    interfaceNode<K>* _right;
    interfaceNode<K>* _left;
    interfaceNode<K>* _father;
};
template <typename K>
BinaryTreeNode<K>::BinaryTreeNode()
{
    this->_element = 0;
    this->_left = NULL;
    this->_right = NULL;
    this->_father = NULL;
}

template <typename K>
K* BinaryTreeNode<K>::getElement(){
    return &this->_element;
}

template <typename K>
void BinaryTreeNode<K>::setElement(K pElement){
    this->_element = pElement;
}

template <typename K>
BinaryTreeNode<K>* BinaryTreeNode<K>::getLeft(){
    return (BinaryTreeNode*)this->_left;
}

template <typename K>
BinaryTreeNode<K>* BinaryTreeNode<K>::getRight(){
    return (BinaryTreeNode*)this->_right;
}

template <typename K>
BinaryTreeNode<K>* BinaryTreeNode<K>::getFather(){
    return (BinaryTreeNode<K>*)this->_father;
}

template <typename K>
void BinaryTreeNode<K>::setLeft(BinaryTreeNode<K> *pLeft){
    this->_left = pLeft;
}

template <typename K>
void BinaryTreeNode<K>::setRight(BinaryTreeNode<K> *pRight){
    this->_right = pRight;
}

template <typename K>
void BinaryTreeNode<K>::setFather(BinaryTreeNode* pFather){
    this->_father = pFather;
}


#endif // BINARYTREENODE_H
