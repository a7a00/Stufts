/*
 * IsisCourse.cpp
 *
 */

#include <iostream>
#include "IsisCourse.h"

using namespace std;

IsisCourse::IsisCourse() {
	class_capacity = 0; // no students allowed in yet
	//roster = new Set();
        //major_waitlist = new Queue();
        //other_waitlist = new Queue();
}

IsisCourse::IsisCourse(int init_capacity) {
	// TODONE: Student writes code here
	class_capacity = init_capacity;
	//roster = new Set();
	//major_waitlist = new Queue();
	//other_waitlist = new Queue();
}

IsisCourse::~IsisCourse() {
	//delete roster;
	//delete major_waitlist;
	//delete other_waitlist;
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
	// TODONE: Student writes code here
	if(s.major)
	{
		if (roster.size() < class_capacity)
		{
			if(roster.add(s)) return ENROLLED;
			else return NONE;
		}
		else
		{
			major_waitlist.enqueue(s);
			return MAJOR_WAITLIST;
		}
	}
	else
	{
		other_waitlist.enqueue(s);
		return OTHER_WAITLIST;
	}
}

bool IsisCourse::drop_student(Student s) {
	if (!((waitlist_position(MAJOR_WAITLIST,s)) && !(waitlist_position(OTHER_WAITLIST,s)))) return false;
	//Explicit failsafe if the student isn't anywhere.
	bool found_student = false; // if we find the student to drop
	// TODONE: Student writes code here

	if(roster.drop(s)) found_student = true;
	if(drop_from_queue(major_waitlist, s)) found_student = true;
	if(drop_from_queue(other_waitlist, s)) found_student = true;
	// if we dropped a student, there should be room on
	// the roster
	update_enrollments();
	return found_student;
}

bool IsisCourse::drop_from_queue(Queue q, Student s) //This actually drops the student.
{
	bool dropped = false;
	Queue* nq = new Queue();
	while(!(q.is_empty())) //For as long as the array is empty,
	{
		Student temp = q.dequeue(); //Pop off a student
		if(temp.name == s.name && temp.major == s.major) dropped = true;
		else nq->enqueue(temp); //Only add him on if he's not the person we want out.
	}
	//delete q;
	//q = *nq;
	while(!(nq->is_empty())) q.enqueue(nq->dequeue()); //Move everything back
	//delete nq;
	return dropped;
}

int IsisCourse::waitlist_position(ENROLLMENT_STATUS status, Student s) {
	// TODONE: Student writes code here
	if(status == MAJOR_WAITLIST) return find_in_queue(major_waitlist, s);
	if(status == OTHER_WAITLIST) return find_in_queue(other_waitlist, s);
	else return -1;
}

int IsisCourse::find_in_queue(Queue &q, Student s) //This function does the heavy lifting for waitlist_position
{
        int index = 0;
	bool flag = false; //This flag keeps track of whether we found the student or not.
        Queue* nq = new Queue(); //New temporary queue
        while(!(q.is_empty()))
        {
                Student temp = q.dequeue(); //Pop off a student and see if they match
                if(temp.name == s.name && temp.major == s.major) flag = true;
		if(!flag) index++; //If we haven't found the student yet, we need to update the index.
                nq->enqueue(temp);
        }
        //delete q;
        //q = *nq;
	while(!(nq->is_empty())) q.enqueue(nq->dequeue()); //Move everything back
	delete nq; //Free up memory
        if(flag) return index;
	else return -1;
}


IsisCourse::ENROLLMENT_STATUS IsisCourse::status(Student s) {
	// returns an ENROLLMENT_STATUS that says which list
	// (or none) that the student is on.
	// TODONE: Student writes code here
	if(roster.is_enrolled(s)) return ENROLLED;
	else if(find_in_queue(major_waitlist, s) != -1) return MAJOR_WAITLIST;
	else if(find_in_queue(other_waitlist, s) != -1) return OTHER_WAITLIST;
	else return NONE;
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
	// TODONE: Student writes code here
	int r = 1;
	Queue* nq = new Queue();
        while(!(waitlist_queue->is_empty()))
        {
                Student temp = waitlist_queue->dequeue();
                cout << r << ". " << temp.name << "\n";
		r++;
                nq->enqueue(temp);
        }
        //delete q;
        //*waitlist_queue = *nq;
	while(!(nq->is_empty())) waitlist_queue->enqueue(nq->dequeue());
	delete nq;
	}

void IsisCourse::update_enrollments() {
	// put students from the waitlists into the class
	// in priority (majors first, then others), up to
	// the class capacity.
	// TODONE: Student writes code here
	//cout << "UE: Roster size is " << roster.size() << " and class capacity is " << class_capacity <<".";
	while(roster.size() < class_capacity && !(major_waitlist.is_empty()))
	{
		bool temp = roster.add(major_waitlist.dequeue());
		if(!temp) cout << "ERR";
	}
	while(roster.size() < class_capacity && !(other_waitlist.is_empty()))
        {
                bool temp = roster.add(other_waitlist.dequeue());
		if(!temp) cout << "ERR";
        }
}
