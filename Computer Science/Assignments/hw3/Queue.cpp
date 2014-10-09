/*
 * Queue.cpp
 *
 */

#include <iostream>
#include "Queue.h"


Queue::Queue()
{
	capacity = INITIAL_SIZE;
	queue_array = new Student[INITIAL_SIZE];
	size = 0;
	back = 0;
	front = 0;
}

SandwichList::~SandwichList()
{
	delete[] queue_array;
}

bool Queue::is_empty()
{
	if (size == 0)
		return true;
	else
		return false;
}

void Queue::incrementPointer(int &i)
{
	i++;
	if(i == capacity) i = 0;
	//return i;
}

Student Queue::dequeue()
{
	Student s = queue_array[front];
	size--;
	incrementPointer(front);
	return s;
}


void Queue::enqueue(const Student& c)
{
	queue_array[back] = c;
	orderCount++;
	incrementPointer(back);
	if(front == back) expand();
}

void Queue::expand()
{
	Student * r = new Student[capacity*2];
	int i = front;
	int c = 0;
	do
	{
		r[c] = queue_array[i];
		c++;
		incrementPointer(i);
	} while (i != back);
	capacity *= 2;
	delete[] queue_array;
	queue_array = r;
	back = c;
	front = 0;
}
