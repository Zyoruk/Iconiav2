#ifndef GEOMETRICFIGURESTREE_H
#define GEOMETRICFIGURESTREE_H

#include <src/dataStructures/geometricFiguresKnowledge/geometricFigure/geometricfigure.h>
#include <src/dataStructures/Tree/binarytree.h>

class GeometricFiguresTree {
public:
    GeometricFiguresTree();
    unsigned int getLenght();
    bool add(short pElement);
    bool remove(short pElement);
    bool ifExists(short pElement);
    GeometricFigure* search(short pElement);

private:
    unsigned int lenght;
    GeometricFigure* _root;

    bool addAux(short pElement , GeometricFigure* pLeaf);
    bool removeAux ( short pElement , GeometricFigure* pLeaf);
    GeometricFigure* searchAux(short pElement, GeometricFigure* pLeaf);
    GeometricFigure* lowestHighest (GeometricFigure* pNode);
    GeometricFigure* highestLowest (GeometricFigure* pNode);
};


#endif // GEOMETRICFIGURESTREE_H
