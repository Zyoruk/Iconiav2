#include <src/dataStructures/geometricFiguresKnowledge/geometricFiguresTree.h>
#include <src/dataStructures/geometricFiguresKnowledge/geometricFigure/geometricfigure.h>

GeometricFiguresTree::GeometricFiguresTree()
{
    this->_root = new GeometricFigure();
    this->lenght = 0;
}

unsigned int GeometricFiguresTree::getLenght(){
    return this->lenght;
}

bool GeometricFiguresTree::add(short pElement)
{
    if(*this->_root->getElement() == 0){
        this->_root->setElement(pElement);
        this->lenght += 1;
        return true;
    }else{
        return addAux(pElement , this->_root);
    }
}

bool GeometricFiguresTree::addAux(short pElement , GeometricFigure* pNode){
    if ( pElement < (*pNode->getElement())){
        if (pNode->getLeft() == NULL){
            GeometricFigure* leftToAdd = new GeometricFigure();
            leftToAdd->setElement(pElement);
            pNode->setLeft(leftToAdd);
        this->lenght += 1;
            return true;
        }else{
            return addAux(pElement , pNode->getLeft());
        }
    }else if (pElement > (*pNode->getElement())){
        if (pNode->getRight() == NULL){
            GeometricFigure* rightToAdd = new GeometricFigure();
            rightToAdd->setElement(pElement);
            pNode->setRight(rightToAdd);
        this->lenght += 1;
            return true;
        }else{
            return addAux(pElement , pNode->getRight());
        }
    }else{
        return false;
    }
}

bool GeometricFiguresTree::remove(short pElement){
    if ( this->lenght == 0){
        std::cout << "Empty Tree";
        return false;
    }else{
        return removeAux(pElement , this->_root);
    }
}

bool GeometricFiguresTree::removeAux (short pElement , GeometricFigure* pCurrentNode){
    GeometricFigure* tmp = this->searchAux(pElement , pCurrentNode);
    if (tmp == 0){
        return false;
    }else{
        if ((tmp->getLeft() == 0 ) && (tmp->getRight() == 0)){
            if (*(tmp->getElement()) == pElement){
                tmp->setElement(0);
                tmp = 0 ;
                this->lenght-= 1;
                return true;
            }else{
                return false;
            }
        }else if ((tmp->getRight() == 0 ) && (tmp->getLeft() != 0)){
            tmp->setElement(*(this->highestLowest(tmp)->getElement()));
            this->lenght-= 1;
            return this->removeAux(pElement , tmp->getLeft());
        }else if ((tmp->getRight() != 0 ) && (tmp->getLeft() == 0)){
            tmp->setElement(*(this->lowestHighest(tmp)->getElement()));
            this->lenght-= 1;
            return this->removeAux(pElement , tmp->getRight());
        }else{
            tmp->setElement(*(this->lowestHighest(tmp)->getElement()));
            this->lenght-= 1;
            return this->removeAux(pElement, tmp->getRight());
        }
    }
}

GeometricFigure* GeometricFiguresTree::search(short pElement){
    if (this->lenght == 0){
        return 0;
    }else{
        return searchAux(pElement , this->_root);
    }
}

GeometricFigure* GeometricFiguresTree::searchAux(short pElement, GeometricFigure* pNode){
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

bool GeometricFiguresTree::ifExists(short pElement){
    if (this->search(pElement) == 0){
        return false;
    }

   return pElement == *(this->search(pElement)->getElement());
}

GeometricFigure* GeometricFiguresTree::highestLowest(GeometricFigure *pNode){
    if (pNode->getLeft() == 0){
        return pNode;
    }else{
        return lowestHighest(pNode->getLeft());
    }
}
GeometricFigure* GeometricFiguresTree::lowestHighest(GeometricFigure* pNode){
    if (pNode->getRight() == NULL){
        return pNode;
    }else{
        return highestLowest(pNode->getRight());
    }
}
