#include "binarytree.h"
#include "cstddef"
#include <iostream>

BinaryTree::BinaryTree()
{
    this->_root = new BinaryTreeNode();
}

bool BinaryTree::add(int pElement)
{
    if(*this->_root->getElement() == NULL){
        this->_root->setElement(pElement);
        return true;
    }else{
        return addAux(pElement , this->_root);
    }
}

bool BinaryTree::addAux(int pElement , BinaryTreeNode* pNode){
    if ( pElement < (*pNode->getElement())){
        if (pNode->getLeft() == NULL){
            BinaryTreeNode* leftToAdd = new BinaryTreeNode();
            leftToAdd->setElement(pElement);
            pNode->setLeft(leftToAdd);
            leftToAdd->setFather(pNode);
        }else{
            return addAux(pElement , pNode->getLeft());
        }
    }else if (pElement > (*pNode->getElement())){
        if (pNode->getRight() == NULL){
            BinaryTreeNode* rightToAdd = new BinaryTreeNode();
            rightToAdd->setElement(pElement);
            pNode->setRight(rightToAdd);
            rightToAdd->setFather(pNode);
        }else{
            return addAux(pElement , pNode->getRight());
        }
    }else{
        return false;
    }
}

BinaryTreeNode* BinaryTree::search(int pElement)
{
    return searchAux(pElement , this->_root);
}

BinaryTreeNode* BinaryTree::searchAux(int pElement, BinaryTreeNode* pleaf)
{
    if (this->_root->getElement() == NULL){
        return NULL;
    }else{
        BinaryTreeNode* _leaf = pleaf;
        if (* _leaf->getElement() == pElement){
            return pleaf;
        }else if(pElement < *_leaf->getElement()){
            return searchAux (pElement , pleaf->getRight());
        }else{
            return searchAux (pElement , pleaf->getLeft());
        }

    }
}

bool BinaryTree::remove(int pElement){
    if ( this->_root->getElement() == NULL){
        std::cout << "Empty Tree";
        return false;
    }else{
        return removeAux (pElement , this->_root);
    }
}

bool BinaryTree::removeAux (int pElement , BinaryTreeNode* pCurrentNode){

}

//BinaryTreeNode* BinaryTree::lowestHighest(BinaryTreeNode *pNode){
//    if (pNode->getLeft() == NULL){
//        return pNode;
//    }else{
//        return lowestHighest(pNode->getLeft());
//    }
//}

//BinaryTree* BinaryTree::highestLowest(BinaryTreeNode* pNode){
//    if (pNode->getRight() == NULL){
//        return pNode;
//    }else if ()
//}
