#include "src/dataStructures/Graph/graph.h"
#include "src/dataStructures/SimpleList/SimpleList.h"
#include "src/genetico/genetico.h"
#include "iostream"
#include "src/dataStructures/stack/stack.h"

using namespace std;

int main()
{
    Genetico* gen = new Genetico(152);
    short res = gen->start(3000, 200);
    cout << res;
    return 0;
}
