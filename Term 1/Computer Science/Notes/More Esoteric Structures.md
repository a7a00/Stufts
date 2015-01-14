# More Esoteric Data Structures

## Sorting a Vector Automagically

In your project, you might want to sort your top 10 songs using the vector's built in functions. You can just call:

```c++
struct songWithFreq
{
	Song* song;
	int frequency;
};

vector<songWithFreq> songs;

bool operator<(const songWithFreq &lhs, const songWithFreq &rhs) //oparator overload
{
	if(lhs.frequency < rhs.frequency) return true;
	else return false;
}

sort(songs.begin(), songs.end());
```

The neat thing is the overload applies *inside* the sort method! Pretty neat, no?

## Back to Skip Lists

So we've derived the best way to build a skip list. (With log base 2 *n* lists) We *could* try to keep the elements perfectly aligned, with each list having half as many elements as the one before it. But what if we don't know how many elements there are? Well, it turns out we basically flip a coin to figure out if we're adding another level. This makes a skip list a *probabilistic data structure*. Every time we flip heads, we create another list and bump up the last added number. If we flip tails, we just add another element to the bottom list. On average, half of the elements move up. Deleting a node is easy, too. Just erase the node in each list.

## Bloom Filters

This is a strange data structure that can tell if something is *not* in a set. Note that it can only tell if something is *probably* in the set, but can tell that something is *definitley* not in the set. The idea is that we have something called a bit array. Here's a sample:

```
[1 0 1 1 0 1 1 1]
```

We start with an empty bit array and *k* hash functions.

```
 0 1 2 3 4 5 6 7
[0 0 0 0 0 0 0 0]

k1=(13-(x%13)), k2=((3+7x)%7)...
```

When we add a value, we hash it and set the value of EACH HASH to 1. To find a value, apply the hash functions and see which elements of the table *should* be 1. If those elements are 1, it's probably in there. It could *not* be in there and those cells are 1 by coincidence, but we know that if any of the cells that should be 1 are 0, that element isn't in there.

Bloom filters are useful if we're working with almmost no space at all. It has that revolutionary Pied Piper level compression. Unfortunatley, you can't remove anything.

So what's the probablility of a false positive? Since each bit has a probability of being set of `1/n`, the probability is `1-1/n`. If there are `k` hash functions, the probability decreases. If we've inserted `m` elements, the probability of a false positive becomes `(1- 1/n)^km`.

-BATTERY DEAD-
