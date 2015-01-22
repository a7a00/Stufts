#
# Makefile for SongSearch, Assignment 6
#
#CXX = clang++
CXX = g++
FLAGS = -Wall -g3 -std=c++11

unittests:
	${CXX} ${FLAGS} -o unittests unittests.cpp songsearch.cpp songsearch.h

searchtest:
	#rm searchtest
	${CXX} ${FLAGS} -o searchtest searchtest.cpp

songsearch:
	${CXX} ${FLAGS} -o songsearch main.cpp songsearch.cpp songsearch.h
	
clean:
	rm -f songsearch

provide_design:
	provide comp15 hw6_design songsearch_design.md

provide:
	provide comp15 hw6 <all your files go here>

