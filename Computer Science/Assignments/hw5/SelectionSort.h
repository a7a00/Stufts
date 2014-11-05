//
//  SelectionSort.h
//  Header File for SelectionSort class
//

#ifndef __Sorting__SelectionSort__
#define __Sorting__SelectionSort__

#include <iostream>

struct arrayWithLength{
        int length;
        int *arr;
};

class SelectionSort {
public:
        SelectionSort(); // constructor
        
        // read in a list of values from stdin
        void readList();
        
        // sort function
        void sort();
        
        // print the array
        void printArray();
        
private:
        arrayWithLength sortArray;
};

#endif /* defined(__Sorting__SelectionSort__) */

