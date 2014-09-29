/*
 * Set.cpp
 *
 */

#include <iostream>
#include "Set.h"

using namespace std;

Set::Set() {
	set_array = new Student[INIT_SET_CAPACITY];
	capacity = INIT_SET_CAPACITY;
	class_size = 0;
}

Set::~Set() {
	delete [] set_array;
}

bool Set::add(Student s) {
	// first search for student, and don't add if already in the set
	if (is_enrolled(s)) {
		return false;
	}
	if (class_size==capacity) {
		expand();
	}
	set_array[class_size]=s;
	class_size++;
	return true; // we successfully enrolled the student
}

bool Set::drop(Student s) {
	// first, find student
	for (int i=0;i<class_size;i++) {
		if (s.name == set_array[i].name) {
			// found the student
			// move all other students up one
			for (int j=i;j<class_size-1;j++) {
				set_array[j]=set_array[j+1];
			}
			class_size--;
			return true;
		}
	}
	return false;
}

bool Set::is_enrolled(Student s) {
	// find student
	for (int i=0;i<class_size;i++) {
		if (s.name == set_array[i].name) {
			// found the student
			return true;
		}
	}
	return false;
}

int Set::size() {
	return class_size;
}

void Set::print_class() {
	for (int i=0;i<class_size;i++) {
		Student s = set_array[i];
		cout << s.name << ", "
				<< (s.major ? "Major" : "Non-Major")
				<< "\n";
	}
}

void Set::expand() {
	Student *new_set_array = new Student[capacity*2];
	for (int i=0;i<class_size;i++) {
		new_set_array[i] = set_array[i];
	}
	delete [] set_array;
	set_array = new_set_array;
	capacity *= 2;
}
