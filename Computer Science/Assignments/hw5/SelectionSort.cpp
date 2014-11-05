//
//  SelectionSort.cpp
//  Sorts integers using the SelectionSort algorithm


#include "SelectionSort.h"

using namespace std;

SelectionSort::SelectionSort(){ // constructor
        sortArray.length = 0;
        sortArray.arr = NULL;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void SelectionSort::readList(){
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

void SelectionSort::sort()
{
	int swap = 0;
	for(int i = 0; i < sortArray.length; i++) //-1?
	{
		swap = i;
		for(int j = i+1; j < sortArray.length; j++)
		{
			if(sortArray.arr[j] < sortArray.arr[swap])
			{
				swap = j;
			}
		}
		int tmp = sortArray.arr[swap];
		sortArray.arr[swap] = sortArray.arr[i];
		sortArray.arr[i] = tmp;
	}
}

void SelectionSort::printArray(){
        for(int i = 0; i < sortArray.length; i++)
	{
		cout << sortArray.arr[i] << "\n";
	}
}


