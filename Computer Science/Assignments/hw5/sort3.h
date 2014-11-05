//
//  sort3.h
//  Header File for Radix Sort class
//

#ifndef __Sorting__Sort3__
#define __Sorting__Sort3__

#include <iostream>

struct arrayWithLength{
        int length;
        int *arr;
};

class RadixSort {
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

