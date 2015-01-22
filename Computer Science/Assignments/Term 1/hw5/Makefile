#
# Makefile for Sorts, Assignment 5
#
#CXX = clang++
CXX = g++
FLAGS = -Wall -Wextra -Wconversion -g

all: SelectionSort.cpp SelectionSort.h main1.cpp \
     sort2.cpp sort2.h main2.cpp \
     sort3.cpp sort3.h main3.cpp
	${CXX} ${FLAGS} -o selectionSort SelectionSort.cpp main1.cpp
	${CXX} ${FLAGS} -o sort2 sort2.cpp main2.cpp
	${CXX} ${FLAGS} -o sort3 sort3.cpp main3.cpp

selectionSort: SelectionSort.cpp SelectionSort.h main1.cpp
	${CXX} ${FLAGS} -o selectionSort SelectionSort.cpp main1.cpp
	
sort2: sort2.cpp sort2.h main2.cpp
	${CXX} ${FLAGS} -o sort2 sort2.cpp main2.cpp
	
sort3: sort3.cpp sort3.h main3.cpp
	${CXX} ${FLAGS} -o sort3 sort3.cpp main3.cpp

sort4: sort4.cpp sort4.h main4.cpp
	${CXX} ${FLAGS} -o sort4 sort4.cpp main4.cpp
	
clean:
	rm -f selectionSort sort2 sort3

make provide:
	provide comp15 hw5 main1.cpp SelectionSort.cpp SelectionSort.h \
	        main2.cpp sort2.cpp sort2.h \
	        main3.cpp sort3.cpp sort3.h \
	        ReadMe.md Makefile

