//
//  main.cpp
//  Sorting
//

#include <iostream>
#include "sort3.h"

using namespace std;

int main()
{
        QuickSort sorter;
        
        sorter.readList();
        sorter.sort();
        cout << "Output:\n";
        sorter.printArray();
}
