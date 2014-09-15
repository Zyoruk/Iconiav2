#ifndef GEOMETRICFIGURE_H
#define GEOMETRICFIGURE_H
#include <iostream>
#include "src/dataStructures/Tree/binarytreenode.h"
#include "src/dataStructures/SimpleList/SimpleList.h"

using namespace std;
template <typename K>
class GeometricFigure : public BinaryTreeNode<K>
{
public:
    GeometricFigure();
    GeometricFigure(short pAngles, string pID ,SimpleList<GeometricFigure<short> >* pSL);
    bool setFigureID(string pfigureID);
    bool setFigureQtyAngles(short pQtyAngles);
    bool setStickToFiguresList(SimpleList<GeometricFigure<short> > * pStickToFiguresList);
    string getFigureID();
    unsigned short getFigureQtyAngles();
    SimpleList<GeometricFigure<short> >* getStickToFiguresList();
private:
    string _figureID;
    unsigned short _figureQtyAngles;
    SimpleList<GeometricFigure<short> >* _stickToFiguresList;
};

template <typename K>
GeometricFigure <K>::GeometricFigure()
{
    this->_figureQtyAngles = this->_element;
    this->_figureID = "" ;
    this->_stickToFiguresList = new SimpleList<GeometricFigure<int> >();
}

template <typename K>
GeometricFigure<K>::GeometricFigure(short pAngles, string pID ,SimpleList<GeometricFigure<short> >* pSL){
    this->_figureQtyAngles = pAngles;
    this->_figureID = pID;
    this->_stickToFiguresList = pSL;
}

template <typename K >
string GeometricFigure <K>::getFigureID(){return this->_figureID;}

template <typename K>
unsigned short GeometricFigure <K>::getFigureQtyAngles(){return this->_figureQtyAngles;}

template <typename K>
SimpleList<GeometricFigure<short> >* GeometricFigure <K>::getStickToFiguresList(){return this->_stickToFiguresList;}

template <typename K >
bool GeometricFigure<K>::setFigureID(string pfigureID){
    if (this->getFigureID() != ""){
        return false;
    }
    this->_figureID = pfigureID;
    return true;
}

template <typename K >
bool GeometricFigure<K>::setFigureQtyAngles(short pQtyAngles){
    if (this->_figureQtyAngles() != 0){
        return false;
    }
    this->_figureQtyAngles = pQtyAngles;
    return true;
}

template <typename K >
bool GeometricFigure<K>::setStickToFiguresList(SimpleList<GeometricFigure<short> >* pStickToFiguresList){
    if (this->_stickToFiguresList != 0){
        return false;
    }
    this->_stickToFiguresList = pStickToFiguresList;
    return true;
}


#endif // GEOMETRICFIGURE_H
