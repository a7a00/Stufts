//
//  sort2.cpp
//  Sorts integers using the Merge Sort algorithm


#include "sort2.h"

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
	if(from != to)
	{
		int midpoint = (from+to)/2;
		sort(from,midpoint);
		sort(midpoint+1,to);
		merge(from,midpoint,to);
	}
	else return;
}

void MergeSort::merge(int from, int midpoint, int to)
{
	int* temp = new int[(to-from)+1];
	int counter1 = from;
	int counter2 = midpoint+1;
	int masterCounter = 0;
	while(counter1 <= midpoint && counter2 <= to)
	{
		if(sortArray.arr[counter1] <= sortArray.arr[counter2])
		{
			temp[masterCounter] = sortArray.arr[counter1];
			counter1++;
		}
		else
		{
			temp[masterCounter] = sortArray.arr[counter2];
                        counter2++;
		}
		masterCounter++;
	}
	if(counter1 > midpoint)
	{
		for(int i = counter2; i <= to; i++)
		{
			temp[masterCounter] = sortArray.arr[i];
			masterCounter++;
		}
	}
	else
	{
		for(int i = counter1; i <= midpoint; i++)
		{
			temp[masterCounter] = sortArray.arr[i];
			masterCounter++;
		}
	}
	for(int i = from; i <= to; i++)
	{
		sortArray.arr[i] = temp[i-from]; //THIS LINE TOOK FOREVER! SO MANY SEGFAULTS BESAUSE OF temp[i]...
	}
	delete[] temp;
}

void MergeSort::printArray(){
        for(int i = 0; i < sortArray.length; i++)
	{
		cout << sortArray.arr[i] << "\n";
	}
}
