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
	if(to <= from)
	{
		//cout << "RETURN\n";
		return;
	}
	int midpoint = (to+from)/2;
	sort (from, midpoint);
	sort (midpoint+1, to);
	//if (sortArray.arr[midpoint] <= sortArray.arr[midpoint+1])
	//{
	//	//cout << "RETURN\n";
	//	return; //We don't need to merge.
	//}
	int pointer1 = from;
	int pointer2 = midpoint+1;
	while (pointer1 <= midpoint && pointer2 <= to)
	{
		if (sortArray.arr[pointer1] <= sortArray.arr[pointer2])
		{
			pointer1++;
		}
		else
		{
			//cout << "********\n" << "From: " << from << " To: " << to << " Midpoint: " << midpoint << " P1: " << pointer1 << " P2: " << pointer2 << "\n";
			int tmp = sortArray.arr[pointer2]; //Turns out you need to save this...
			//cout << "TMP: " << tmp;
			for(int i = 0; i < (pointer2-pointer1); i++)
			{
				sortArray.arr[pointer1+i+1] = sortArray.arr[pointer1+i];
				//pointer1++;
			}
			sortArray.arr[pointer1] = tmp;
			pointer1++;
			midpoint++;
			pointer2++;
		}
	}
	//cout << "NOW PRINTING ARRAY F" << from << "T" << to << "M" << midpoint << ":\n";
	//printArray();
}

void InPlaceMergeSort::printArray(){
	//cout << "------\n";
        for(int i = 0; i < sortArray.length; i++)
	{
		cout << sortArray.arr[i] << "\n";
	}
}
