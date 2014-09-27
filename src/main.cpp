using namespace std;
#include "src/dataStructures/Graph/graph.h"
#include "iostream"
int main()
{
    Graph<int>* temp = new Graph<int>();
    temp->add(98);
    temp->add(198);
    temp->connect(98,198);
    temp->moveAB(98,198);
    return 0;
}

