//
//  sort4.cpp
//  Sorts integers using the Radix Sort algorithm

#include <cassert>
#include "sort4.h"

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
	merge(0, (sortArray.length/2), (sortArray.length/2)+1, sortArray.length-1);
}

//General information on block swapping from http://ak.hanyang.ac.kr/papers/tamc2008.pdf
void InPlaceMergeSort::merge(int start1, int end1, int start2, int end2)
{
	while (true)
	{
		// Find the first place in the second array where we need to put in something from the first array
		int midpoint = findBinary(start2, end2, sortArray.arr[start1], true);
		// rotate in the first array
		int amount = midpoint - end1;
		rotate(start1, midpoint, (end1-start1));
		if (end1 == midpoint) return;//break;
		//Find new ranges
		start2 = midpoint;
		start1 += amount;
		end1 = start2;
		start1 = findBinary(start1, end1, sortArray.arr[start1], false);
		if (start1 == end1) return;//break;
	}
}

//The following are essential operations for an in place sort that handle the swapping of data.

void InPlaceMergeSort::swap(int a, int b) //In a long function, this will save a lot of typing.
{
	int tmp = a;
	a = b;
	b = tmp;
}

void InPlaceMergeSort::blockSwap(int first, int second, int swapLength) //This takes 2 chunks of an array of the same length,
//and swaps them without changing any order.
{
	assert((second-first) < swapLength);
	for(int i = 0; i < swapLength; i++)
	{
		swap(sortArray.arr[first+i], sortArray.arr[second+i]);
	}
}

void InPlaceMergeSort::reverse(int start, int end) //This is useful for rotations
{
	for(int i = ((start+end)/2) - 1; i >= 0; i--)
	{
		swap(sortArray.arr[start+i], sortArray.arr[end-i-1]);
	}
}

void InPlaceMergeSort::rotate(int start, int end, int amount) //Shifts the elements some number of spaces. Algorithm
//Taken from our work on circular queues.
{
	reverse(start, (start+amount));
	reverse((start+amount), end);
	reverse(start, end);
}

int InPlaceMergeSort::findLinear(int start, int end, int find) //For unsorted chunks
{
	for(int i = start; i < end; i++)
	{
		if(sortArray.arr[i] ==find) return i;
	}
	return -1;
}

int InPlaceMergeSort::findBinary(int start, int end, int find, bool firstPlace) //For sorted chunks.
//The boolean determines if we should find the first or last place an element should be inserted.
{
	while(start < end)
	{
		int midpoint = ((end-start)/2)+start;
		if(sortArray.arr[midpoint] < find) start = midpoint + 1;
		else end = midpoint;
	}
	if(start == end)
	{
		if(firstPlace)
		{
			if(sortArray.arr[start] < find) start++;
		}
		else
		{
			if(sortArray.arr[start] <= find) start++;
		}
	}
	return start;
}

void InPlaceMergeSort::quickSort(int start, int end) //No, it's not quick sort, it's just a small insertion sort,
//which is much faster on small arrays than merging.
//Algorithm taken from SoftPedia.
{
	for(int i = start + 1; i < end; i++)
	{
		int tmp = sortArray.arr[i];
		int j = i-1;
		while(j > start && sortArray.arr[j-1] > tmp)
		{
			swap(j, j+1);
			j--;
		}
	}
}

void InPlaceMergeSort::printArray(){
        for(int i = 0; i < sortArray.length; i++)
	{
		cout << sortArray.arr[i] << "\n";
	}
}
