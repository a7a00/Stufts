#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Queue.h"

#define NUM_STUDENTS 11

using namespace std;

void print_queue_status(Queue &q) {
        cout << "Queue is " << (q.is_empty() ? "empty.\n" : "not empty.\n");
}

int main() {
        Student students[NUM_STUDENTS] = {
                        Student("Green,Alice",true),
                        Student("Blue,Misha",false),
                        Student("Yellow,John",false),
                        Student("Orange,Friya",true),
                        Student("Pink,Julia",true),
                        Student("Black,Henry",false),
                        Student("Cyan,Barnaby",true),
                        Student("Red,Justin",true),
                        Student("Violet,Chester",false),
                        Student("Fuchsia,Rebecca",false),
                        Student("Beige,Barker",true)
        };
        Queue q;

        for (int i=0;i<NUM_STUDENTS;i++) {
                q.enqueue(students[i]);
        }

        for (int i=0;i<NUM_STUDENTS;i++) {
                Student s = q.dequeue();
                print_queue_status(q);
                cout << "Student name: " << s.name <<
                                ". Major? " <<
                                (s.major ? "Yes.\n" : "No.\n");
        }
        return 0;
}
