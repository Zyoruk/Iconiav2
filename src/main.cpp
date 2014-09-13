#include <iostream>

using namespace std;
#include "src/dataStructures/SimpleList/Node/SimpleListNode.h"
#include "src/dataStructures/SimpleList/SimpleList.h"
#include "src/dataStructures/Tree/binarytreenode.h"
#include "src/dataStructures/Tree/binarytree.h"
int main()
{
    cout << "Testing simple list\n";
    SimpleList<int>* mySL = new SimpleList<int>();
    mySL->append(98);
    mySL->append(7);
    mySL->append(78);
    mySL->append(934);
    mySL->append(9);

    cout << "Searching for 7 ... "<<  mySL->ifExists(7) <<"\n";
    cout << "Searching for 98 ... "<<  mySL->ifExists(98) <<"\n";
    cout << "Searching for 934 ... "<<  mySL->ifExists(934) <<"\n";
    cout << "Searching for -7 ... "<<  mySL->ifExists(-7) <<"\n";
    cout << "Current lenght: " << mySL->getLenght() <<"\n";
    cout << "Index of 9 ... " << mySL->indexOf(9) <<"\n";
    cout << "Element at index 4...  " << mySL->elementAt(4)<<"\n";
    cout << "Element at index 5...  " << mySL->elementAt(5)<<"\n";
    cout << "Removing 98 ... ";
    cout << mySL->remove(98) << "\n";
    cout << "Current lenght: " << mySL->getLenght()<<"\n";
    cout << "Searching for 7 ... "<<  mySL->ifExists(7) <<"\n";
    cout << "Searching for 98 ... "<<  mySL->ifExists(98) <<"\n";
    cout << "Searching for 934 ... "<<  mySL->ifExists(934) <<"\n";


}

