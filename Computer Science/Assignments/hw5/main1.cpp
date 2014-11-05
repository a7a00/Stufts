//
//  main.cpp
//  Sorting
//

#include <iostream>
#include "SelectionSort.h"

using namespace std;

int main()
{
        SelectionSort sorter;
        
        sorter.readList();
        sorter.sort();
        cout << "Output:\n";
        sorter.printArray();
}
