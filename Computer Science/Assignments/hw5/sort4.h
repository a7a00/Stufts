//
//  sort4.h
//  Header File for Radix Sort class
//

#ifndef __Sorting__Sort4__
#define __Sorting__Sort4__

#include <iostream>

struct arrayWithLength{
        int length;
        int *arr;
};

class InPlaceMergeSort {
public:
        InPlaceMergeSort(); // constructor
	~InPlaceMergeSort();

        // read in a list of values from stdin
        void readList();
        
        // sort function
        void sort();
	void sort(int from, int to);

	void merge(int start1, int end1, int start2, int end2);
	void swap(int a, int b);
	void blockSwap(int first, int second, int swapLength);
	void reverse(int start, int end);
	void rotate(int start, int end, int amount);
	int findLinear(int start, int end, int find);
	int findBinary(int start, int end, int find, bool firstPlace);
	void quickSort(int start, int end);
        
        // print the array
        void printArray();
        
private:
        arrayWithLength sortArray;
};

#endif

