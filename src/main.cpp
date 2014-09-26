using namespace std;
#include "src/dataStructures/Graph/graph.h"
#include "iostream"
int main()
{
    Graph<int>* temp = new Graph<int>();
    temp->add(98);
    temp->add(100);
    temp->connect(98,100);
    temp->remove(100);
    cout << temp->exists(98);
    return 0;
}

