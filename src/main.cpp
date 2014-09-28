using namespace std;
<<<<<<< HEAD
#include "src/genetico/genetico.h"
int main()
{
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
>>>>>>> eb1a777f276f6a811beaf354efb4d2e2a790bec7
    return 0;
}

