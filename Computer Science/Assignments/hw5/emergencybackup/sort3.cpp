//
//  sort3.cpp
//  Sorts integers using the Quick Sort algorithm


#include "sort3.h"

using namespace std;

QuickSort::QuickSort(){ // constructor
        sortArray.length = 0;
        sortArray.arr = NULL;
}

QuickSort::~QuickSort()
{
	delete[] sortArray.arr;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void QuickSort::readList(){
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

void QuickSort::sort()
{
	sort(0, sortArray.length-1);
}

void QuickSort::sort(int from, int to)
{
	int pivot = (from+2)/2;
	int pointer1 = from;
	int pointer2 = to;
	while(pointer1 <= pointer2)
	{
		while(sortArray.arr[pointer1] < pivot)
		{
			pointer1++;
		}
		while(sortArray.arr[pointer2] > pivot)
		{
			pointer2--;
		}
		if(pointer1 <= pointer2)
		{
			int tmp = sortArray.arr[pointer1];
			sortArray.arr[pointer1] = sortArray.arr[pointer2];
			sortArray.arr[pointer2] = tmp;
			if(pivot == pointer1) pivot = pointer2; //These are catch cases. If the pivot it swapped,
			//we pick a new one.
			else if(pivot == pointer2) pivot = pointer1;
			pointer1++;
			pointer2--;
		}
	}
	if(from < pointer2) sort(from, pointer2); //Recursive calls
	if(to > pointer1) sort(pointer1, to);
}

void QuickSort::printArray(){
        for(int i = 0; i < sortArray.length; i++)
	{
		cout << sortArray.arr[i] << "\n";
	}
}
