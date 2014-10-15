#
# Makefile for Binary Search Tree
#
CXX = clang++
FLAGS =  -g -Wall 

bst: BinarySearchTree.cpp BinarySearchTree.h main.cpp pretty_print.cpp
	${CXX} ${FLAGS} -o hw4 BinarySearchTree.cpp \
		main.cpp pretty_print.cpp
clean:
	rm -f hw4

provide:
	provide comp15 hw4 main.cpp BinarySearchTree.cpp BinarySearchTree.h \
	        pretty_print.cpp ReadMe.md Makefile

