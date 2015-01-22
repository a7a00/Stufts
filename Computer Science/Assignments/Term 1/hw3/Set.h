/*
 * Set.h
 *
 * This class is a Set, which holds Students.
 * The Set has the following public methods:
 * bool Set::add(Student s)
 * bool drop(Student s);
 * bool is_enrolled(Student s);
 * void print_class();
 * int size();
 *
 * Do not change the Set, as it is completely built for you.
 */

#ifndef SET_H_
#define SET_H_

#include "Student.h"

#define INIT_SET_CAPACITY 10

class Set {
public:
	Set();
	~Set();

	bool add(Student s);
	bool drop(Student s);

	bool is_enrolled(Student s);
	void print_class();

	int size();

private:
	Student *set_array;
	int capacity;
	int class_size;
	void expand();
};

#endif /* SET_H_ */
