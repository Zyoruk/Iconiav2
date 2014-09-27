using namespace std;
#include "src/dataStructures/Graph/graph.h"
int main()
{
    Graph<int>* temp = new Graph<int>();
    temp->add(98);
    temp->add(100);
    temp->connect(98,100);
    return 0;
}

