using namespace std;
#include "src/dataStructures/geometricFiguresKnowledge/geometricFigure/geometricfigure.h"
int main()
{
    string ID = "square";
    SimpleList<GeometricFigure>* tmp = new SimpleList<GeometricFigure>();

    GeometricFigure* test  = new GeometricFigure((short)4 , ID, tmp);

    return 0;
}

