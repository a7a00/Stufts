//
//  sort3.h
//  Header File for Quick Sort class
//

#ifndef __Sorting__Sort3__
#define __Sorting__Sort3__

#include <iostream>

struct arrayWithLength{
        int length;
        int *arr;
};

class QuickSort {
public:
        QuickSort(); // constructor
	~QuickSort();

        // read in a list of values from stdin
        void readList();
        
        // sort function
        void sort();
	void sort(int from, int to);
        
        // print the array
        void printArray();
        
private:
        arrayWithLength sortArray;
};

#endif

