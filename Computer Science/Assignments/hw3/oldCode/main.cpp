/* main.cpp
 * Comp 15 
 * Spring 2014 
 * Lab 4
 */
 
#include "sandwichList.h"
#include <iostream>
using namespace std;

int main(){

  SandwichList slist;
  Order testCases[15];
  Order temp;

  string s = "sandwich";
  string c = "customer";

  // generate 15 test cases
  for(int i = 0; i < 15; i++){
    testCases[i].sandwich = s;
	testCases[i].customerName = c;
	testCases[i].orderNbr = i;
	testCases[i].fries = i%2;
  }

	//enqueue one
  slist.enqueue(testCases[0]);

	//remove one
  temp = slist.dequeue();
	
  // see if sandwich customer 0 0 is a match with itself
  slist.printOrder(testCases[0]);
  cout << "matches" << endl;
  slist.printOrder(temp);
  cout << endl;

	// 10 times enqueue two and remove one, which enqueues 1, 1, 2, 2, ... 9, 9
	// and removes the first 10, which would be 1, 1 - 4, 4
  for(int i = 0; i < 10; i++){
	slist.enqueue(testCases[i]);
	slist.enqueue(testCases[i]);
	temp = slist.dequeue();
  }
  
  cout << "Should print customers 5-9 twice each, then empty Q message:\n";
  
	// Print customers 5, 5, 6, 6, ... 9, 9, then print empty message
  for(int i = 0; i < 11; i++){
    if(!slist.isEmpty()){
	  temp = slist.dequeue();
	  slist.printOrder(temp);
	}
	else
	  cout << "Q empty - no more sandwiches" << endl;
  }

	// enqueue 15 Orders to test expansion
	for(int i = 0; i < 15; i++)
		slist.enqueue(testCases[i]);
		
  return 0;
}
