/* sandwichList.h
 * Comp 15 
 * Spring 2014
 * Lab 4
 */

#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;
const int INITIAL_SIZE = 5;


struct Order {
        string sandwich;
        string customerName;
        int orderNbr;
        bool fries;
};


class SandwichList{

public:
        SandwichList();
	~SandwichList();

        //Interface for queue
        Order dequeue();
        void enqueue(const Order& sandwich);
        bool isEmpty();
        int size();	
	void incrementPointer(int &i);

        //test function if you like
        //not the best design, shouldn't be queues
        //job to print an order
        void printOrder(Order s);

private:
        //capacity is size of array, not amount stored in list
        int capacity;
        
        // orderCount is the number of orders in the queue
        int orderCount;
        
        Order* orders;
        void expandList();

        //use front and back to figure out how much is in the list
        int front;
        int back;	
};

#endif
