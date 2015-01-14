# ReadMe for COMP 15 HW3 - ISIS Course Roster and Waitlists

## Overview

This program allows users to add students to a course, much as you can on ISIS. (Or SIS, as we're now calling it for obvious reasons). Students with majors will be placed in the course right away, or on a priority waitlist if there's no space. Non-major students will be put on a special waitlist and will only be added in once everyone's signed up.

## Files

* `hw3` - The binary executable.
* `main.cpp` - Used for testing. Creates students, adds them, expands the class size and repeats to make sure everything's working.
* `IsisCourse.cpp` - Controls adding students and expanding the class. Also determines where prospecive studetns should go.
* `IsisCourse.h` - Function definitions for `Isiscourse.cpp`.
* `Set.cpp` - Acts as the roster for the class. Can have elements added to it and report its own size/emptiness.
* `Set.h` - Function definitions for `Set.cpp`.
* `Queue.cpp` - Acts as the waitlist. Can add elements to the end of the queue and pop elements off the beginning.
* `Queue.h` - Function definitions for `Queue.cpp`.
* `Student.h` - Contains information about the student, including name, major and enrollment. Also includes the struct for enrollmnt.
* `Makefile`- For compiling.

## Compiling

Use the included makefile with no flags.

## Data Structures

This project relies on a set for the class roster, queues for the waitlist.

## Acknowledgements

Special thanks to my good friend caffiene. Also to my roommate who helped me figure out a pointer bug.
