# Sets and Queues

## Unix Autocompletes

We all know that you can use the tab key to autocomplete and save your fingers, but Ctrl+R is a useful shortcut as well. Hitting Ctrl-R allows you to search your history and save yourelf some agony.

## Sets

A set is a very simple abstract data type. All that matters is that:

* None of the values are the same.
* No order is enforced.

We can build it with a simple dynamic array or linked list. There are a few simple functions we need to have:

* Add an element that isn't already there
* Remove an element from the set
* See if an element is in the set
* Get the size of the set

We can also include operators used on mathematical sets, such as union, intersection and subtraction. Because of their lack of order, we can use sets for things like rosters and the like.

### Dynamic Arrays

Since we don't care about the order, we can tack new elements on the end. Searching the set for the purpose of addition and removal, however, takes a lot of time and has linear complexity. Union and intersection are no easier. Searching both lists with nested loops has quadratic complexity.

## Queues

A queue is very similar to its cousin, the stack, except that deltion is done at the opposite end from insertion, rather than the same end. Because of this, queues have "First in, First out" structures. Their operations are similar to those of queues, as well:

* Enqueue an object at the end of the list
* Dequeue an object from the front of the list
* See if the queue is empty

We can easily do this with a dynamic array by adding elements to the end of the array and moving the pointer to the end of the queue. Dequeueing is as simple as changing the pointer to the head by 1. You don't even have to change anything; moving pointers is all you need to do to to dequeue stuff.

Some other things we can implement with queues:

* Get the size
* Print the queue without dequeueing (for debugging)
* Peek at the front and the back

To enqueue an element, set `queue[back]` to the element and increment both `back` and `size`. To dequeue, of course, we just have to incrememnt `front` and decrement `count`. Of course, this is really wasteful and you'll have to expand your array a lot. So why don't we mind that we're wasting a ton of space? Well, generally enqueueing and dequeueing happen at the same rate, which means it's simple enough to make a circular queue.

### Circular Queues

What do we do when we run out of space? We implement a circular queue, which is what happens when we move the "back" pointer back to 0 and keep going until we hit the "head" pointer. Let's take a look:

Assume we have a queue of the numbers 1-10. (I'll use hex for convinience) We've already dequed 1, 2 and 3, so we have an array that looks like this:

```
XXX456789AXX
   ^      ^
   f      b
```

Pop on 11 and 12.

```
XXX456789ABC
   ^        ^
   f        b
```

If we want to add 13, 14 and 15, but "back" is past the array, have it circle around.

```
DEF456789ABC
   ^
   f,b
```

When we want to add another number, we can see that the front and back are the same and that's how we know it's absolutley necessary to expand. To avoid mistakes, we need to make sure that `size == 0`, the only other case this would happen, is not true.

### Expanding a Queue

Expanding a queue is fairly easy:

```c++
for(int i = 0; i < size; i++)
{
	newQueue[i] = queue[(front + i) % size];
}
front = 0;
back = size; //This is still the old size
```

This expansion not only expands the list, but reorders it as well. This isn't the only method, though. You can enqueue and dequeue in expansion as well.

### Examples

* Printing Queues
* Ticket counters
* FTP servers
* Call centers
* ISIS (The class management system, not the angry beheady people)
* Prof. Gregg's research on processor optimization
