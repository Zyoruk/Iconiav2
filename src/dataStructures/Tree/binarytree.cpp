#include "binarytree.h"
#include "cstddef"
#include <iostream>

BinaryTree::BinaryTree()
{
    this->_root = new BinaryTreeNode();
}

bool BinaryTree::add(int pElement)
{
    if(this->_root->getElement() == NULL){
        this->_root->setElement(pElement);
        return true;
    }else{
        return addAux(pElement , this->_root);
    }
}

bool BinaryTree::addAux(int pElement , BinaryTreeNode* pleaf){
    if (*pleaf->getElement() == pElement){
        return false;
    }else if (*pleaf->getElement() < pElement){
        if (pleaf->getRight()->getElement() == NULL){
            BinaryTreeNode* _rightNodeToAdd = new BinaryTreeNode();
            _rightNodeToAdd->setElement(pElement);
            pleaf->setRight(_rightNodeToAdd);
            _rightNodeToAdd->setFather(pleaf);
            return true;
        }else{
            return addAux(pElement , pleaf->getRight());
        }
    }else{
        if (pleaf->getLeft()->getElement() == NULL){
            BinaryTreeNode* _leftNodeToAdd = new BinaryTreeNode();
            _leftNodeToAdd->setElement(pElement);
            pleaf->setLeft(_leftNodeToAdd);
            _leftNodeToAdd->setFather(pleaf);
            return true;
        }else{
            return addAux(pElement , pleaf->getLeft());
        }
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
    }else if (this->_root->getElement()== pElement){
        this->_root = NULL;
    }else{
        return removeAux (pElement , this->_root);
    }
}

bool BinaryTree::removeAux (int pElement , BinaryTreeNode* pleaf){
    if (pleaf->getLeft() == NULL && pleaf->getLeft() == NULL){
        if (pleaf->getFather()->getLeft()->getElement() == pleaf->getElement()){
            pleaf->getFather()->setLeft(NULL);
        }else{
            pleaf->getFather()->setRight(NULL);
        }
        pleaf->setFather(NULL);
        delete (pleaf);
        return true;
    }else if(pleaf->getElement() == pElement){
        if (pleaf->getLeft() == NULL){
            pleaf->getFather()->setRight(pleaf->getRight());
            pleaf->setFather(NULL);
            pleaf->setRight(NULL);
            delete pleaf;
            return true;
        }else if (pleaf->getRight() == NULL){

        }
    }else{
        if (pElement < pleaf->getElement()){
            if (pleaf->getLeft() != NULL){

            }
        }
    }
}
