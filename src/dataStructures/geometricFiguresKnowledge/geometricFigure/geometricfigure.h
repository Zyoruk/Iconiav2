#ifndef GEOMETRICFIGURE_H
#define GEOMETRICFIGURE_H
#include <iostream>
#include "src/dataStructures/Tree/binarytreenode.h"
#include "src/dataStructures/SimpleList/SimpleList.h"

using namespace std;
class GeometricFigure : public BinaryTreeNode<short>
{
public:
    GeometricFigure();
    GeometricFigure(short pAngles, string pID ,SimpleList<GeometricFigure>* pSL);
    bool setFigureID(string pfigureID);
    bool setFigureQtyAngles(short pQtyAngles);
    bool setStickToFiguresList(SimpleList<GeometricFigure> * pStickToFiguresList);
    string getFigureID();
    unsigned short getFigureQtyAngles();
    SimpleList<GeometricFigure>* getStickToFiguresList();
private:
    string _figureID;
    unsigned short _figureQtyAngles;
    SimpleList<GeometricFigure >* _stickToFiguresList;
};


GeometricFigure ::GeometricFigure()
{
    this->_figureQtyAngles = this->_element;
    this->_figureID = "" ;
    this->_stickToFiguresList = new SimpleList<GeometricFigure>();
}


GeometricFigure::GeometricFigure(short pAngles, string pID ,SimpleList<GeometricFigure>* pSL){
    this->_figureQtyAngles = pAngles;
    this->_figureID = pID;
    this->_stickToFiguresList = pSL;
}


string GeometricFigure ::getFigureID(){return this->_figureID;}


unsigned short GeometricFigure ::getFigureQtyAngles(){return this->_figureQtyAngles;}


SimpleList<GeometricFigure>* GeometricFigure::getStickToFiguresList(){return this->_stickToFiguresList;}


bool GeometricFigure::setFigureID(string pfigureID){
    if (this->getFigureID() != ""){
        return false;
    }
    this->_figureID = pfigureID;
    return true;
}


bool GeometricFigure::setFigureQtyAngles(short pQtyAngles){
    if (this->_figureQtyAngles != 0){
        return false;
    }
    this->_figureQtyAngles = pQtyAngles;
    return true;
}


bool GeometricFigure::setStickToFiguresList(SimpleList<GeometricFigure>* pStickToFiguresList){
    if (this->_stickToFiguresList != 0){
        return false;
    }
    this->_stickToFiguresList = pStickToFiguresList;
    return true;
}


#endif // GEOMETRICFIGURE_H
