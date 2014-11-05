//
//  sort3.cpp
//  Sorts integers using the Radix Sort algorithm


#include "sort3.h"

using namespace std;

RadixSort::RadixSort(){ // constructor
        sortArray.length = 0;
        sortArray.arr = NULL;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void RadixSort::readList(){
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

void RadixSort::sort()
{
	
}

void RadixSort::printArray(){
        for(int i = 0; i < sortArray.length; i++)
	{
		cout << sortArray.arr[i] << "\n";
	}
}


