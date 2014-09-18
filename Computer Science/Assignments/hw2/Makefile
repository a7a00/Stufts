#
# Makefile for List_linked_list
#
CXX = clang++
FLAGS =  -g -Wall 

cards_linked_list: List_linked_list.cpp List_linked_list.h \
     card.h card.cpp hand.h hand.cpp main.cpp
	${CXX} ${FLAGS} -o hw2 List_linked_list.cpp main.cpp \
	        hand.cpp card.cpp
clean:
	rm -f hw2

make provide:
	provide comp15 hw2 main.cpp List_linked_list.cpp List_linked_list.h \
	        hand.cpp hand.h card.cpp card.h \
	        ReadMe.md Makefile