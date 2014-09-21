#include <src/dataStructures/geometricFiguresKnowledge/geometricFigure/geometricfigure.h>
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
