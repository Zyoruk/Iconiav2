#include "binarytree.h"
#include "cstddef"
#include <iostream>

BinaryTree::BinaryTree()
{
    this->_root = new BinaryTreeNode();
}

//void BinaryTree::printRoot(){
//    std::cout << "\nroot "<<this->_root << "\n";
//    std::cout << "root element " << *(this->_root->getElement())<<"\n";

//    std::cout << "root left node pointer " << this->_root->getLeft() << "\n";
//    std::cout << "root left node element pointer " << this->_root->getLeft()->getElement() << "\n";
//    std::cout << "root left node element " << *(this->_root->getLeft()->getElement()) << "\n";

//    std::cout << "root right node pointer " << this->_root->getRight() << "\n";
//    std::cout << "root right node element pointer " << this->_root->getRight()->getElement() << "\n";
//    std::cout << "root right node element " << *(this->_root->getRight()->getElement()) << "\n";
//}
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
    }else if (*this->_root->getElement()== pElement){
        this->_root = NULL;
        return true;
    }else{
        return removeAux (pElement , this->_root);
    }
}

bool BinaryTree::removeAux (int pElement , BinaryTreeNode* pleaf){
    //if the node is a leaf, just remove.
    if (pleaf->getLeft() == NULL && *(pleaf->getLeft()->getElement()) == NULL){
        //To know if the leaf is the right or left of its father.
        if (*(pleaf->getFather()->getLeft()->getElement()) == *(pleaf->getElement())){
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
