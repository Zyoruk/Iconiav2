using namespace std;
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
    //temp->moveAB(98,198);
    return 0;
}

