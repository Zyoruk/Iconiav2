using namespace std;
<<<<<<< HEAD
#include "src/genetico/genetico.h"
int main()
{
=======
#include "src/dataStructures/Graph/graph.h"
#include "src/dataStructures/SimpleList/SimpleList.h"
#include "iostream"
int main()
{
    Graph<int>* temp = new Graph<int>();
    temp->add(98);
    temp->add(198);
    temp->add(200);
    temp->add(56);
    temp->connect(198,200);
    temp->connect(200,56);
    temp->connect(98,198);
<<<<<<< HEAD
    temp->moveAB(98,198);
>>>>>>> eb1a777f276f6a811beaf354efb4d2e2a790bec7
=======
    //temp->moveAB(98,198);
>>>>>>> f84636fea4eb9ecccecf985252792bfdbabd0957
    return 0;
}

