//
//  sort3.cpp
//  Sorts integers using the In Place Merge Sort algorithm


#include "sort3.h"

using namespace std;

MergeSort::MergeSort(){ // constructor
        sortArray.length = 0;
        sortArray.arr = NULL;
}

MergeSort::~MergeSort()
{
	delete[] sortArray.arr;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void MergeSort::readList(){
        int currentCapacity = 10;
        sortArray.arr = new int[currentCapacity];
        
        while (cin >> sortArray.arr[sortArray.length]) {
                ++sortArray.length;
                if (sortArray.length==currentCapacity) {
                        int *temp = new int[currentCapacity*2];
                        for (int i=0;i<currentCapacity;i++) {
                                temp[i] = sortArray.arr[i];
                        }
                        delete [] sortArray.arr;
                        sortArray.arr = temp;
                        currentCapacity *= 2;
                }
        }
}

void MergeSort::sort()
{
	sort(0, sortArray.length-1);
}

void MergeSort::sort(int from, int to)
{
	
}

void MergeSort::merge(int from, int midpoint, int to)
{
	
}

void MergeSort::printArray(){
        for(int i = 0; i < sortArray.length; i++)
	{
		cout << sortArray.arr[i] << "\n";
	}
}
