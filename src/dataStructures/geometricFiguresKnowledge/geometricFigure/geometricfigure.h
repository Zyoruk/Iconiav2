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

#endif // GEOMETRICFIGURE_H
