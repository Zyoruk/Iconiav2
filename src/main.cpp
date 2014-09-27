using namespace std;
<<<<<<< HEAD
#include "src/genetico/genetico.h"
int main()
{
    Genetico* temp = new Genetico(30 , 52); //el numero y su cociente deben ser par // el arreglo parcial hace que haya tres hijos cuando se dan 100 elementos
=======
#include "src/dataStructures/Graph/graph.h"
#include "iostream"
int main()
{
    Graph<int>* temp = new Graph<int>();
    temp->add(98);
    temp->add(198);
    temp->connect(98,198);
    temp->moveAB(98,198);
>>>>>>> fa4dda088f3d44da7cdeb50fcc8b1426a83c4f5c
    return 0;
}

