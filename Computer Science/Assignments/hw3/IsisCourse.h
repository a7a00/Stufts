/*
 * IsisCourse.h
 *
 * This class holds a roster (Set), and two waitlists (Queues)
 * for a Tufts course.
 *
 * When a student who is majoring in the subject attempts to enroll
 * in the course, he or she immediately goes into the course,
 * unless the course is at capacity.
 * If the class is at capacity, the student goes onto the major waitlist.
 *
 * When a student who is not a major attempts to enroll in the course,
 * he or she immediately goes onto the other (non-major) waitlist.
 *
 * If the capacity of the course is raised (it will never be lowered),
 * the students proceed off the waitlist immediately, until the
 * class is at capacity (full). Students come off the major waitlist
 * first (in the order they were put on the list), and then if the
 * major waitlist is full, students come off the other waitlist and
 * into the course, until the course is at capacity.
 *
 * When a student is dropped from the course, students are added from
 * the waitlist(s) until the capacity is reached
 * (this is a simplification).
 *
 */

#ifndef ISISCOURSE_H_
#define ISISCOURSE_H_

#include "Student.h"
#include "Set.h"
#include "Queue.h"

class IsisCourse {
public:
	// the status of a student
	// NONE: not enrolled in the class or on a waitlist
	// ENROLLED: on the class roster (i.e., in the course)
	// MAJOR_WAITLIST: on the majors' waitlist
	// OTHER_WAITLIST: on the non-majors' waitlist
	enum ENROLLMENT_STATUS {NONE, ENROLLED, MAJOR_WAITLIST, OTHER_WAITLIST};

	// no-argument constructor
	IsisCourse();

	// constructor with initial capacity
	IsisCourse(int init_capacity);

	// destructor
	~IsisCourse();

	// update the class capacity. When you update the capacity,
	// you must also move students off of the waitlists (if any are
	// on the waitlists). Students from the major waitlist move
	// into the class first, then students from the other waitlist
	// go into the class. The class can never have more students
	// than the capacity.
	void set_class_cap(int cap);

	// returns class capacity (written for you)
	int get_class_cap() { return class_capacity; }

	// Attempts to enroll a student into the class.
	// Majors go directly into the class, and non-majors
	// go directly onto the waitlist, even if there is space
	// in the class.
	// Simplification: you do not need to check if a student is
	// on a waitlist already before placing that student onto
	// the appropriate waitlist.
	ENROLLMENT_STATUS enroll_student(Student s);

	// Attempts to drop a student from the class AND the waitlists
	// Returns true if student was successfully dropped,
	// false if the student was not on any list
	bool drop_student(Student s);

	// Updates the enrollment for the class up to the capacity.
	// This is always executed when the capacity is increased,
	// but can also be executed to fill up the class to its
	// current capacity.
	void update_enrollments();

	// returns the number of students enrolled in the course
	int get_roster_size() { return roster.size(); }

	// returns the waitlist position for a student for a
	// particular waitlist (MAJOR_WAITLIST or OTHER_WAITLIST)
	int waitlist_position(ENROLLMENT_STATUS status, Student s);

	// returns the status of a student (NONE, ENROLLED,
	// MAJOR_WAITLIST, or OTHER_WAITLIST)
	ENROLLMENT_STATUS status(Student s);

	// prints the roster (ENROLLED) or waitlist
	// (either MAJOR_WAITLIST or OTHER_WAITLIST)
	// in the following form (names should be in priority from
	// the waitlist):
	// 1. student.name
	// 2. student.name
	// 3. student.name
	// etc.
	void print_list(ENROLLMENT_STATUS status);
private:
	// the roster for the course
	Set roster;

	// the waitlist for majors
	Queue major_waitlist;

	// the waitlist for non-majors
	Queue other_waitlist;

	// the class capacity
	int class_capacity;
};

#endif /* ISISCOURSE_H_ */
