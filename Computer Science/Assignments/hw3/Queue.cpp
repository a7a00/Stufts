/*
 * Queue.cpp
 *
 */

#include <iostream>
#include "Queue.h"


Queue::Queue()
{
	capacity = 2;
	queue_array = new Student[2];
	size = 0;
	back = 0;
	front = 0;
}

Queue::~Queue()
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

void Queue::incrementIndex(int &index) //Helper function so I would have to handle this
//exceptional case every time I moved in the queue.
{
	index++;
	if(index == capacity) index = 0;
	//return i;
}

Student Queue::dequeue() //Return the student at the front, then move the front away.
{
	Student s = queue_array[front];
	size--;
	incrementIndex(front);
	return s;
}


void Queue::enqueue(const Student& c) //Add an element behind the tail, move tail back.
{
	queue_array[back] = c;
	size++;
	incrementIndex(back);
	if(front == back) expand();
}

void Queue::expand()
{
	Student * newArray = new Student[capacity*2]; //New array with double the capacity.
	int index = front;
	int count = 0;
	do //We want the code here to be run at least once no matter what.
	{
		newArray[count] = queue_array[index]; //The  next (or first) element of
		//the new array is the next (or first value of the old queue
		count++; //We can just increase the count.
		incrementIndex(index); //TO account for strange cases n the old queue, we have
		//to use the helper function
	} while (index != back); //Stop when we reach the back of the old queue.
	capacity *= 2; //Update capacity
	delete[] queue_array; //Free the old memory
	queue_array = newArray; //Reassign the pointer
	back = count; //Reassign the back
	front = 0; //Reset the front
	//delete[] r;
}
