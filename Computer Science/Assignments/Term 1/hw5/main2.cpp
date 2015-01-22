//
//  main.cpp
//  Sorting
//

#include <iostream>
#include "sort2.h"

using namespace std;

int main()
{
        MergeSort sorter;
        
        sorter.readList();
        sorter.sort();
        cout << "Output:\n";
        sorter.printArray();
}
