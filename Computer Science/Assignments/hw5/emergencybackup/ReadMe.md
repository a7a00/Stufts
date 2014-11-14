# ReadMe for COMP 15 HW5 - Sorting Assignment 

This project contains three methods for sorting an array of integers: selection
sort, merge sort and an in place implementation of merge sort.

## Files

* `main` files - These 3 files take user input, build arrays from it, and call
their respective sorts, and are virtually identical.
* `SelectionSort.cpp/h` - Sorts a given array according to a linear selection
sort.
* `sort2.cpp/h` - Performs a typical merge sort algorithm on an array with
time complexity O(n*log*n) and space compexity O(n).
* `sort3.cpp/h` - Sorts an array according to an in place merge sort algorithm
with O(1) space complexity, but O(n) or O(n^2) time complexity. (I'm not really
sure...)
* `Makefile` - For compiling.

## Compliling

Use the included makefile with no flags.

## Algorithms

### Selection Sort

This algorithm's pretty simple. You just go down the array and find the smallest
unsorted element. Then just do a simple swap to move the element into the
sorted section.

### Merge Sort

This algorithm splits the array into incrementally smaller and smaller pieces. 
It then works its way up and merges the smaller pieces into bigger ones until
we're done.

### 

### Acknowledgements

Many thanks to the TA's of Halligan for all their patience and help demystifying
 my algorithms and associated scribbles.
