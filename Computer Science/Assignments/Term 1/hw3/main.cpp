#include <iostream>
#include <sstream>
#include <cstdlib>
#include <time.h>

#include "IsisCourse.h"

#define NUM_STUDENTS 10

using namespace std;

void print_enrollment(IsisCourse::ENROLLMENT_STATUS es) {
	switch(es) {
	case IsisCourse::NONE:
		cout << "NONE\n";
		break;
	case IsisCourse::ENROLLED:
		cout << "ENROLLED\n";
		break;
	case IsisCourse::MAJOR_WAITLIST:
		cout << "MAJOR_WAITLIST\n";
		break;
	case IsisCourse::OTHER_WAITLIST:
		cout << "OTHER_WAITLIST\n";
		break;
	default:
		cout << "Not a valid output!\n";
		break;
	}
}

int main() {
	Student s1("Indigo,Charlie",false);
	Student s2("Maroon,Stacy",true);

	Student students[NUM_STUDENTS] = {
			Student("Green,Alice",true),
			Student("Blue,Misha",false),
			Student("Yellow,John",true),
			Student("Orange,Friya",false),
			Student("Pink,Julia",true),
			Student("Black,Henry",false),
			Student("Cyan,Barnaby",true),
			Student("Red,Justin",false),
			Student("Violet,Chester",true),
			Student("Fuchsia,Rebecca",false),
	};
	IsisCourse comp15(3); // cap of 20 students;

	for (int i=0;i<NUM_STUDENTS;i++) {
		comp15.enroll_student(students[i]);
	}

	cout << comp15.drop_student(s1) << "\n";
	cout << comp15.drop_student(s2) << "\n";

	return 0;
}
