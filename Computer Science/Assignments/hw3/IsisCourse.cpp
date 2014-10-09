/*
 * IsisCourse.cpp
 *
 */

#include <iostream>
#include "IsisCourse.h"

IsisCourse::IsisCourse() {
	class_capacity = 0; // no students allowed in yet
	roster = new Set();
        major_waitlist = new Queue();
        other_waitlist = new Queue();
}

IsisCourse::IsisCourse(int init_capacity) {
	// TODONE: Student writes code here
	class_capacity = init_capacity;
	roster = new Set();
	major_waitlist = new Queue();
	other_waitlist = new Queue();
}

IsisCourse::~IsisCourse() {
	delete roster;
	delete major_waitlist;
	delete other_waitlist;
}

void IsisCourse::set_class_cap(int cap) {
	class_capacity = cap;
	if (roster.size() < class_capacity) {
		update_enrollments();
	}
}

IsisCourse::ENROLLMENT_STATUS IsisCourse::enroll_student(Student s) {
	// See the enrollment logic from the assignment handout or
	// the IsisCourse.h file!
	// TODO: Student writes code here
	if(s.major)
	{
		if (roster.size() < class_capacity)
		{
			if(roster.add(s)) return ENROLLED;
		}
		//Else add to major q
	}
}

bool IsisCourse::drop_student(Student s) {
	bool found_student = false; // if we find the student to drop
	// TODO: Student writes code here


	// if we dropped a student, there should be room on
	// the roster
	update_enrollments();
	return found_student;
}

int IsisCourse::waitlist_position(ENROLLMENT_STATUS status, Student s) {
	// TODO: Student writes code here

}

IsisCourse::ENROLLMENT_STATUS IsisCourse::status(Student s) {
	// returns an ENROLLMENT_STATUS that says which list
	// (or none) that the student is on.

	// TODO: Student writes code here
}

void IsisCourse::print_list(ENROLLMENT_STATUS status) {
	Queue *waitlist_queue;
	Queue temp_queue;
	if (status == ENROLLED) {
		roster.print_class();
		return;
	}
	if (status == MAJOR_WAITLIST) {
		waitlist_queue = &major_waitlist;
	}
	else {
		waitlist_queue = &other_waitlist;
	}
	// now handle printing the queue

	// TODO: Student writes code here
}

void IsisCourse::update_enrollments() {
	// put students from the waitlists into the class
	// in priority (majors first, then others), up to
	// the class capacity.

	// TODO: Student writes code here
}
