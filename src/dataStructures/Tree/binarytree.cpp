#include "binarytree.h"
#include "cstddef"
BinaryTree::BinaryTree()
{
    this->_root = new BinaryTreeNode();
}

bool BinaryTree::add(int pElement){
    if(this->_root->getElement() == NULL){
        this->_root->setElement(pElement);
        return true;
    }else if(*search(pElement)->getElement() == pElement){
        return false;
    }else{
        BinaryTreeNode* _current = this->_root;
        if (*_current->getElement() < pElement){
            while (_current->getRight() != NULL){
                _current = _current->getRight();
            }
            BinaryTreeNode* _newRight = new BinaryTreeNode();
            _newRight->setElement(pElement);
            _current->setRight(_newRight);
        }else {
        }
    }
}
BinaryTreeNode* BinaryTree::search(int pElement){
    return searchAux(pElement , this->_root);
}

BinaryTreeNode* BinaryTree::searchAux(int pElement, BinaryTreeNode* pleaf){
    if (this->_root->getElement() == NULL){
        return NULL;
    }else{
        BinaryTreeNode* _leaf = pleaf;
        if (* _leaf->getElement() == pElement){
            return pleaf;
        }else if(pElement < *_leaf->getElement()){
            return searchAux (pElement , pleaf->getLeft());
        }else{
            return searchAux (pElement , pleaf->getLeft());
        }

    }
}
