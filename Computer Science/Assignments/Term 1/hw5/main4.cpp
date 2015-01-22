//
//  main.cpp
//  Sorting
//

#include <iostream>
#include "sort4.h"

using namespace std;

int main()
{
        InPlaceMergeSort sorter;
        
        sorter.readList();
        sorter.sort();
        cout << "Output:\n";
        sorter.printArray();
}
