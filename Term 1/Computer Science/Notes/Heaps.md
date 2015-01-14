# Heaps

## A Note

You lazy bastards now have server space tied to your CS accounts! Dump your terrible web apps into `/h/agould02/public_html` and `chmod` them to executable files. Easy as pie.

## Heaps

Using arrays for priority queues for an array is a pain in the ass because there are incredibly long index times. We can do better, and we do this using a simple property. If you have a jar of rocks and sand and shake it, the rocks always rise to the top, simply by virtue of them being bigger. We can use this to great effect in a heap, which is basically a tree with only one condition. Children have a higher priority key than their parents. (A max heap inverts this, but what's important isthat you keep the order.)

```
      5
    /   \
  10     8
 /  \   / \
 12 11 14 13
/  \
22 43
```

This is a *binary* heap, meaning that each node has 2 kids. As you can see, concepts of order are thrown out the window. Swapping the left and right children of a node doesn't effectually change the heap at all. Heaps are also like stacks in that we're only allowed to pop off the top.

There's one other rule that's crucial. The binary tree MUST be full, which means the heap above is actually wrong, but I'm too lazy to fill in the rest. This isn't an explicit rule, but we'll see why it's important later.

## Storing a Heap

We store a heap with an array! To make the math easier, we put the root at position 1. The tree above therefore becomes the array:

0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15
--- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | ---
X | 5 | 10 | 8 | 12 | 11 | 14 | 13 | 22 | 43 | X | X | X | X | X | X

You'll note that this is in level order. So, for any element at position `i`,

* The left child is at `2i`
* The right child is at `2i+1`
* The parent is at `i/2`

As you can see, this is amazingly quick o index because we *already know where everything is*. No more tree crawling!

## Priority Operations

###  `minElement()`

Return the element with the smallest key. Literally just return `array[1]`. Constant efficiency. Yay!

### `insertItem(heap, element)`

This is a bit trickier, but there's an algorithm for it:

* Insert the element at index `heapSize+1`, which probably wrecks the heap property.
* Compare the added element to its parent. (At element `n/2`)
* If the element is greater than the parent, swap the 2.
* Repeat as necessary.

Grab the full demo [here](http://www.cs.usfca.edu/~galles/visualization/Heap.html).

The average complexity of a heap insert is *constant* because there's no traversal. This is amazing.

### `removeMin()`

Again, simpler tha you'd think:

* Get rid of the last element in the array and put it at the root
* "Bubble down", swapping it with the smaller of the two children until it hits the bottom of the tree.

Logarithmic complexity here, but that's still pretty good.

## Building Heaps

This is actually really cool. Just throw everything into the array, and then find the lowest level with kids. Bubble down, move up and repeat. Constant time. Boom.

![Cool, no?](../res/Mind\ Blown.gif)

Next week, sorts! Oh, boy...
