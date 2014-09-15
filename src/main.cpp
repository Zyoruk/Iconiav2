using namespace std;
#include "src/dataStructures/geometricFiguresKnowledge/geometricFigure/geometricfigure.h"
int main()
{
    string ID = "square";
    SimpleList<GeometricFigure<short> >* tmp = new SimpleList<GeometricFigure<short> >();

    GeometricFigure<int> * test  = new GeometricFigure <int> ((short)4 , ID, tmp);
    return 0;
}

