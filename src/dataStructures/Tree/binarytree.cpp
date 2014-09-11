#include "binarytree.h"
#include "cstddef"
#include <iostream>

BinaryTree::BinaryTree()
{
    this->_root = new BinaryTreeNode();
    this->lenght = 0;
}

unsigned int BinaryTree::getLenght(){
    return this->lenght;
}


bool BinaryTree::add(int pElement)
{
    if(*this->_root->getElement() == NULL){
        this->_root->setElement(pElement);
        this->lenght += 1;
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
        this->lenght += 1;
            return true;
        }else{
            return addAux(pElement , pNode->getLeft());
        }
    }else if (pElement > (*pNode->getElement())){
        if (pNode->getRight() == NULL){
            BinaryTreeNode* rightToAdd = new BinaryTreeNode();
            rightToAdd->setElement(pElement);
            pNode->setRight(rightToAdd);
            rightToAdd->setFather(pNode);
        this->lenght += 1;
            return true;
        }else{
            return addAux(pElement , pNode->getRight());
        }
    }else{
        return false;
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

BinaryTreeNode* BinaryTree::search(int pElement){
    if (this->lenght == 0){
        return 0;
    }else{
        return searchAux(pElement , this->_root);
    }
}

BinaryTreeNode* BinaryTree::searchAux(int pElement, BinaryTreeNode* pNode){
    if (*pNode->getElement() == pElement){
        return pNode;
    }else if (*pNode->getElement() < pElement){
        if (pNode->getRight()== 0){
            return 0;
        }
        return searchAux(pElement , pNode->getRight());
    }else{
        if(pNode->getLeft() == 0){
            return 0;
        }
        return searchAux(pElement, pNode->getLeft());
    }
}

bool BinaryTree::removeAux (int pElement , BinaryTreeNode* pCurrentNode){

}
bool BinaryTree::ifExists(int pElement){
    if (this->search(pElement) == 0){
        return false;
    }

   return pElement == *(this->search(pElement)->getElement());
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
