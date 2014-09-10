#include "binarytree.h"
#include "cstddef"
#include <iostream>

BinaryTree::BinaryTree()
{
    this->_root = new BinaryTreeNode();
}

void BinaryTree::printRoot(){
    std::cout << this->_root << "\n";
    std::cout << *(this->_root->getElement())<<"\n";
}
bool BinaryTree::add(int pElement)
{
    std::cout << "Entering add method ...";
    if(*this->_root->getElement() == NULL){
        this->_root->setElement(pElement);
        return true;
    }else{
        return addAux(pElement , this->_root);
    }
}

bool BinaryTree::addAux(int pElement , BinaryTreeNode* pleaf){
    if (*(pleaf->getElement()) == pElement){
        return false;
    }else if (*(pleaf->getElement()) < pElement){
        if (*(pleaf->getRight()->getElement()) == NULL || pleaf->getRight()== NULL){
            BinaryTreeNode* _rightNodeToAdd = new BinaryTreeNode();
            (*_rightNodeToAdd).setElement(pElement);
            (*pleaf).setRight(_rightNodeToAdd);
            (*_rightNodeToAdd).setFather(pleaf);
            return true;
        }else{
            return addAux(pElement , pleaf->getRight());
        }
    }else{
        if (*(pleaf->getLeft()->getElement()) == NULL || pleaf->getLeft() == NULL){
            BinaryTreeNode* _leftNodeToAdd = new BinaryTreeNode();
            (*_leftNodeToAdd).setElement(pElement);
            (*pleaf).setLeft(_leftNodeToAdd);
            (*_leftNodeToAdd).setFather(pleaf);
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
    }else if (*this->_root->getElement()== pElement){
        this->_root = NULL;
        return true;
    }else{
        return removeAux (pElement , this->_root);
    }
}

bool BinaryTree::removeAux (int pElement , BinaryTreeNode* pleaf){
    //if the node is a leaf, just remove.
    if (pleaf->getLeft() == NULL && pleaf->getLeft() == NULL){
        //To know if the leaf is the right or left of its father.
        if (pleaf->getFather()->getLeft()->getElement() == pleaf->getElement()){
            pleaf->getFather()->setLeft(NULL);
        }else{
            pleaf->getFather()->setRight(NULL);
        }
        pleaf->setFather(NULL);
        delete (pleaf);
        return true;
    //If the node is the same we want to remove.
    }else if(*pleaf->getElement() == pElement){
        //We are removing a right node, and the father doesnt have a left one.
        if (pleaf->getLeft() == NULL){
            pleaf->getFather()->setRight(pleaf->getRight());
            pleaf->setFather(NULL);
            pleaf->setRight(NULL);
            delete pleaf;
            return true;
        //We are removing a left node, and the father doesnt have a right one.
        }else if (pleaf->getRight() == NULL){
            pleaf->getFather()->setLeft(pleaf->getLeft());
            pleaf->setFather(NULL);
            pleaf->setLeft(NULL);
            delete pleaf;
            return true;
        }else{
            // Removing a node that has both left and right.
            // This would be the fourth case.
            BinaryTreeNode* _temp = lowestHigher(pleaf);
            lowestHigher(pleaf)->setElement(*pleaf->getElement());
            pleaf->setElement(*_temp->getElement());
            delete _temp;
            return true;
        }
    }else{
        if (pElement < *pleaf->getElement()){
            if (pleaf->getLeft() != NULL){
                return removeAux(pElement , pleaf->getLeft());
            }else{
                return false;
            }
        }else{
            if (pleaf->getRight() != NULL){
                return removeAux(pElement , pleaf->getRight());
            }else{
                return false;
            }
        }
    }
}

BinaryTreeNode* BinaryTree::lowestHigher(BinaryTreeNode *pnode){
    if (pnode->getLeft() == NULL){
        return pnode;
    }else{
        return lowestHigher(pnode->getLeft());
    }
}
