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
    //if it is a leaf
    if (pCurrentNode->getLeft() == NULL && pCurrentNode->getRight() == NULL){
        //is it is the same
        if (pElement == *(pCurrentNode->getElement())){
            return true;
        }else{
<<<<<<< HEAD

            //if has both leaves
            // Removing a node that has both left and right.
            // This would be the fourth case.
            BinaryTreeNode* _temp = lowestHigher(pleaf);
            lowestHigher(pleaf)->setElement(*pleaf->getElement());
            pleaf->setElement(*_temp->getElement());
            delete _temp;
            return true;

=======
            return false;
        }

    //If the element to remove is higher than the current node and the right is not null
    }else if (*(pCurrentNode->getElement()) < pElement && pCurrentNode->getRight() != NULL){
        return removeAux(pElement , pCurrentNode->getRight());
    //If the element to remove is lower than the current node and the left is not null
    }else if (*(pCurrentNode->getElement()) > pElement && pCurrentNode->getLeft() != NULL){
        return removeAux(pElement , pCurrentNode->getLeft());
>>>>>>> 422101285cf8da03feb87db49ffac0c95505f062
    }else{

        if (pCurrentNode->getLeft() == NULL){
            pCurrentNode->setElement(*(lowestHighest(pCurrentNode->getRight())->getElement()));
        }else{
           // pCurrentNode->setElement(*(highestLowest(pCurrentNode->getLeft())->getElement()));
        }
    }


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
