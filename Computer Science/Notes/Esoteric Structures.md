# Esoteric Sorts & Project Review

## Possible Song Search Structures

We need to do plenty of things here, storing individual songs, as well as their lyrics, and putting them in a quickly searchable format. We also need to rank songs by word count.

Songs are complicated things, that should be able to store multiple pieces of information and record multiple functions. As a result, a class is probably the way to go. We can store these in an `std::vector<>`, which is basically a dynamic array where all the messy details are handled for you. Nice bracket notation is already overloaded for you and there are also premade methods like `size()` included. They also come with these things called "iterators", which are data types that return relative positions in the vector, not index numbers. We can also use vectors to store all the lyrics we're using.

How do we grep for lyrics, though? Well, first we strip away caps and punctuation. You then do whatever you want because it's a final project, man. Do whatever you want!

## Skip Lists

Linked Lists have several problems:

* You have to go through the whole damn thing.
* You can't access specific elements.
* You can't binary search it, even if it's sorted.

So what do we do? A pointer to the middle could help, as could pointers in each quarter.

I have just made an ass of myself by not knowing the difference between the 4 and the 2. Anyhow, skip lists work the way local and express lines work. If I want to get from Union Square to Bronx Science, I don't take the local unless I'm some sort of sick masochist. I take the express and transfer at 125th. (Well, actually the 4 goes from express to local, but that's not the point. Assume NYC has a subway system that makes sense.) Skip lists work exactly the same way. We then do some calculus that I'm too lazy to TeX out, but the search cost (represented by `|L1|+(n/|L1|)`) can be minimized by any other function, so the ideal space between nodes is the square root of `n`. If the list gets really, really big, just add an express-express line! This jacks the efficiency from `2*sqrt(n)` to `3*cbrt(n)`. If we have `log(n)` sorted list, we end up with our optimal `2log(n)` efficiency. This looks and acts like a binary tree!
