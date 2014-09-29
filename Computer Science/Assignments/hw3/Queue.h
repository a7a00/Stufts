/*
 * Queue.h
 *
 * This is the header for a Queue with the following methods:
 * void enqueue(Student c);
 * Student dequeue();
 * bool is_empty();
 *
 * You may add private members to this class, but you cannot change
 * the public section.
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "Student.h"

#define QUEUE_INIT_CAPACITY 2

class Queue {
public:
	// constructor
	Queue();

	// destructor
	~Queue();

	// enqueue a char onto at the back of the queue
	void enqueue(Student c);

	// dequeue a char from the front of the queue
	Student dequeue();

	// returns true if there are no elements in the
	// queue, false if the queue has elements
	bool is_empty();

private:
	// The private section of this header file assumes
	// you will use a dynamic array for your queue.
	// Feel free to use a linked-list instead.
	// You may update the private section of this class, but
	// not the public section.
	Student *queue_array; // the dynamic array for the queue
	int capacity; // the capacity of the queue 
	int size; // how many characters there are in the queue
	int front; // the front of the queue
	int back;  // the back of the queue
	void expand(); // expand the circular queue
};

#endif /* QUEUE_H_ */
