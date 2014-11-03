# More Sorts

## Labs and Stuff

Tomorrow's lab has been posted! It's about heaps, and you'll have to build heaps, remove the minimum element, and downheap. Tons of fun! 

## The `sed` Command

`sed` is a stream editor, which means that it can change data fed to it. So, for example:

`sed s/pattern1/pattern2/g < file1`

would swap every instance of `pattern1` with `pattern2`. You can also replace those slashes with dashes if you want to include dashes.

You can do other fun stuff, too! Google it!

## Merge Sort

You know what this is. It's the recursive divide-and-conquer sort.

In order to understand merge sort, you need to understand one key concept, merging 2 sorted lists. Say we have 2 lists that are sorted.

**3** 5 11      **1** 8 10

See which bold number is the least, add it to the list, and move THAT cursor (not both!) to the right.

**3** 5 11      1 **8** 10

The final list is now `[1]`. Keep doing this until you've reached the end of both lists.

You already know how to recursively split and merge, so that's not an issue.

## Quicksort

Pretty fast, but can degrade to horrible complexity. You've implemented this before-the basic idea is that you recursivley move all elements less than the pivot to one side, and all ekements greater than the pivot to the other. Easy.

How do we pick the pivot? Well, if you make it the leftmost element, this causes havoc with sorted lists. You could pick the middle and do a middle out sort, but we don't know what the elements are.

![Richard, why do you keep showing up?](../res/PIEDPIPER.gif)

Hehehehe...

Anyhow, a better option would be to sort it from the median of the first, middle and end.

We can do this in place as well. Use cursors and iterate through the list until you find an element that needs to be to the left of the pivot and an element that needs to be to the right of the pivot, and swap 'em. Repeat this until the left and right cursors cross.

## Radix Sort

All right, this son of a bitch is kinda tough. It's NOT a comparison sort like the other one's we're looking at. On each pass it looks at a different decimal place. Buckets are individual arrays, and for decimal numbers, we have 10 buckets (0-9).

This is tough to type out. Get the example [here](https://cs.auckland.ac.nz/software/AlgAnim/radixsort.html). This thing is amazingly fast, but space complexity is iffy. Plus, modulus operators take a long time.
