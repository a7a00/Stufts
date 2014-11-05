//
//  sort2.h
//  Header File for Merge Sort class
//

#ifndef __Sorting__Sort2__
#define __Sorting__Sort2__

#include <iostream>

struct arrayWithLength{
        int length;
        int *arr;
};

class MergeSort {
public:
        RadixSort(); // constructor
        
        // read in a list of values from stdin
        void readList();
        
        // sort function
        void sort();
        
        // print the array
        void printArray();
        
private:
        arrayWithLength sortArray;
};

#endif

