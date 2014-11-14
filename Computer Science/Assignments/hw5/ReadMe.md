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

### In-Place Merge Sort

This algorithm starts out the same way as regular merge sort, but the merge
function is different. Instead of having 2 arrays, we have 2 different sections
of one array, both sorted. So how do we merge these 2 parts without losing
data? The answer lies in the fact that we can easily reverse a section of the
array without losing extra space. Three reverses in a row can act as swapping
two parts of an array:

```
[ABCD] -> [DC]BA -> CD[BA] -> CDAB
```

So we can now think of our array as 2 arrays, provided we can only perform one
action:

```
[AB{CD}] [{EF}GH] -> [ABEF] [CDEH]
```

These 2 swapped pieces have to be the same size, and have to be the end of the
first array and the beginning of the second. So the algorithm works like this:

1. Perform a search to find the first place an element in the first list is
greater than an element in the second.
2. Swap the piece following that element's index in the first array with the
piece before that element's index in the second array.
3. Recursively merge this way with a base case of single element arrays.

(I used a binary search for step 1 because of speed issues.)

Now that we have a merge algorithm, we can just implement merge sort like
normal.

### Acknowledgements

Many thanks to the TA's of Halligan for all their patience and help demystifying
 my algorithms and associated scribbles.
