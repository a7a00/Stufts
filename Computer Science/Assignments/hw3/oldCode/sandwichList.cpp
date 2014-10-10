/* sandwichList.cpp
 * Comp 15 
 * Spring 2014 
 * Lab 4
 */

#include "sandwichList.h"


SandwichList::SandwichList()
{
	capacity = INITIAL_SIZE;
	orders = new Order[INITIAL_SIZE];
	orderCount = 0;

	back = 0;
	front = 0;
}

SandwichList::~SandwichList()
{
	delete[] orders;
}

bool SandwichList::isEmpty()
{
	if (size() == 0)
		return true;
	else
		return false;
}


int SandwichList::size()
{
        return orderCount;
        // you could use the following arithmetic (but be careful):
	//return (back - front + capacity) % capacity;
}

void SandwichList::incrementPointer(int &i)
{
	i++;
	if(i == capacity) i = 0;
	//return i;
}

//function to remove Order from the front of the queue
Order SandwichList::dequeue()
{

	//if(isEmpty()) return NULL;
// TODO: Debug
	Order o = orders[front];
	orderCount--;
	incrementPointer(front);
	//if(front == back) expandList();
	return o;
}

//add an element, make sure it is not full, if it is call expand funciton
void SandwichList::enqueue(const Order& sw)
{
// TODO: Debug
	orders[back] = sw;
	orderCount++;
	incrementPointer(back);
	if(front == back) expandList();
}

//Double the queue size, copy the values, and reset back and front
void SandwichList::expandList()
{

// TODO: Debug
	Order * r = new Order[capacity*2];
	int i = front;
	int c = 0;
	do
	{
		r[c] = orders[i];
		c++; //hehe. Also, we don't have to use the increment function here; we won't run out of space.
		incrementPointer(i);
	} while (i != back);
	capacity *= 2;
	delete[] orders;
	orders = r;
	back = c;
	front = 0;
}

void SandwichList::printOrder(Order s)
{
	cout << s.sandwich << " " << s.customerName << " " << s.orderNbr << " " << s.fries;
	cout << endl;
}



