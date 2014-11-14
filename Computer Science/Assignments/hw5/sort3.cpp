//
//  sort3.cpp
//  Sorts integers using the In Place Merge Sort algorithm


#include <cassert>
#include "sort3.h"

using namespace std;

InPlaceMergeSort::InPlaceMergeSort(){ // constructor
        sortArray.length = 0;
        sortArray.arr = NULL;
}

InPlaceMergeSort::~InPlaceMergeSort()
{
	delete[] sortArray.arr;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void InPlaceMergeSort::readList(){
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

void InPlaceMergeSort::sort()
{
	sort(0, sortArray.length-1);
}

void InPlaceMergeSort::sort(int from, int to)
{
	//cout << "--------\n" << "From: " << from << "\nTo: " << to << "\nMidpoint: " << (to+from)/2 << "\n";
	//printArray();
	//int flag = 0;
	//assert(from < to);
	if(from >= to)
	{
		//cout << "RETURN\n";
		return;
	}
	int midpoint = (to+from)/2;
	sort (from, midpoint);
	sort (midpoint+1, to);
	merge(from, midpoint, to);
}

void InPlaceMergeSort::merge(int from, int midpoint, int to)
{
	if(to == from) return;
	//base case for length 2?
	int pointer1 = (from+midpoint)/2;
	int pointer2 = midpoint+pointer1;
	int count = (midpoint-from)/2;
	while(count > 0)
	{
		if(sortArray.arr[pointer1] > sortArray.arr[pointer2])
		{
			pointer1 -= count;
			pointer2 += count;
		}
		else
		{
			pointer1 += count;
			pointer2 -= count;
		}
		count /= 2;
	}
	reverse(pointer1, pointer2); //Initial swap done with a full reverse
	reverse(pointer1, midpoint); //These 2 reverses get the 2 halves back into proper order
	reverse(midpoint, to);
	merge(from, (from+midpoint)/2, midpoint); //No -1 here. Otherwise single element arrays would be messed up.
	merge(midpoint, (midpoint+to)/2, to);
	//And the arrays are sorted, so we don't care about sorting midpoint twice, anyway.
}

void InPlaceMergeSort::reverse(int from, int to)
{
	if(to == from) return;
	int pointer1 = from;
	int pointer2 = to;
	while(pointer1 < pointer2)
	{
		int tmp = sortArray.arr[pointer1];
		sortArray.arr[pointer1] = sortArray.arr[pointer2];
		sortArray.arr[pointer2] = tmp;
		pointer1++;
		pointer2--;
	}
}

void InPlaceMergeSort::printArray(){
	//cout << "------\n";
        for(int i = 0; i < sortArray.length; i++)
	{
		cout << sortArray.arr[i] << "\n";
	}
}
