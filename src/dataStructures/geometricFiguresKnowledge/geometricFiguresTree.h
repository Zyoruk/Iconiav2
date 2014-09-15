#ifndef GEOMETRICFIGURESTREE_H
#define GEOMETRICFIGURESTREE_H

#include <src/dataStructures/geometricFiguresKnowledge/geometricFigure/geometricfigure.h>
#include <src/dataStructures/Tree/binarytree.h>

class GeometricFiguresTree : public BinaryTree <GeometricFigure<short> >{
public:
    GeometricFiguresTree();

};

#endif // GEOMETRICFIGURESTREE_H
