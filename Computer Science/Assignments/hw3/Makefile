#
# Makefile for ISIS Course
#
CXX = clang++
FLAGS =  -g -Wall 

isis_course: IsisCourse.cpp IsisCourse.h \
     Set.cpp Set.h Queue.cpp Queue.h \
     Student.h main.cpp
	${CXX} ${FLAGS} -o hw3 IsisCourse.cpp Set.cpp Queue.cpp main.cpp
clean:
	rm -f hw3

provide:
	provide comp15 hw3 main.cpp IsisCourse.cpp IsisCourse.h \
	        Set.cpp Set.h Queue.cpp Queue.h Student.h \
	        ReadMe.md Makefile
