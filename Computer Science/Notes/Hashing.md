# Hashing

## Regex

A regular expression is a sequence of characters that forms a search pattern. The most basic regular expression is a singular character. Multiple letters and ranges are represented in single bracket, like. `[ab]` or `[a-c]`. Dots are wildcards, so `a..` would give every string of a followed by 2 characters. A star matches 0 or 1 repeasts of the previous character. `a*` gives every string of a's. You can also anchor characters to the front of a string with `^` or the end of a string with `$`. You can escape any of these characters with `\`. Grep and sed use regex, as do JS and Perl and Python and  other stuff like that.

## Hashing

Let's say we have a bunch of 2 letter words and their definitions. The words are keys in this case, and the definitions are values. We can store this information as a list/array, a stack, a queue, or a tree-like structure. Problem is, these all have trade-offs. How do we implement things so that `find()`, `insert()` and `remove()` all have constatnt time? The answer is a new approach called hashing. The "hash function" returns what are known as "hash codes". These must be deterministic, and should be fast and distributed for ease of access. A hash function is any algorithm that maps data to a number. A sample with out data set could be:

1. Assign each letter value from 0 to 25.
2. Compute `(26*A)+(1*B)` for every 2 number sequence A, B.

That's it! If we want to make it a 3-letter word, we'd add in a term with 676 - 26 raised to the second power. The reason we use powers of 26 is to make sure that there are no possible duplicates.

We then load the definitions into the array at the index of their hashes. So, with this algorithm, "ox" becomes 387, so the pointer to the definition of "ox" is loaded into `array[387]`. Since there are 676 possible 2 letter words, we need a 676 space array.

Now, what if we have really, really, really long words? We can't make arrays that take up yottabytes of space. A good way to do this is with a modulus. This is what's known as a *compression function*. It shrinks the amunt of spaces we need.

This poses a problem. Say or hash function is based off the last digit of a number and we have a 10 space array to do it. We can add 3 and then 4, no problem. But if we add 14, there's already a 4 in the slot! This is what's known as a *hash collision*.

OH MY GOD .SWP FILES I LOVE YOU THANK YOU FOR SAVING MY DATA.

Anyhow, we solve the collision issue by having each spot in the hash table point to a linked list. Remember, though, that if you do this, you have to store the key *with* the definition. Problem is you then throw away constant time. Also, linked lists are annoying.

What happens when you try to add two elements with the same key is up to the programmer.

### Load Factor

The load factor is just the number of keys over the number of slots in the hash table. Most commercial ones are around .5-.7. Keep in mind that a tiny load factor doesn't even mean much. Even 2,500 keys in a 1,000,000 slot hash table have a 95% chance of a random collision.
