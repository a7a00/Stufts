# HW6 Design Proposal

My design focuses on a really fast read-in time, so the data structure is extremley minimal. Songs are stroed in a simple dynamic array and Searching is done with a pattern matching algorithm.

## Reading In Data

The methods in `read_lyrics.cpp` might make my job a lot easier, or I might choose to code my own. Basically, there's a dynamic arra (pr possibly a vector; no real difference in this case) full of Song objects. Each Song has:

* A title
* An artist
* A `string` containing all the song's lyrics
* An `int` to keep track of how many occurences of wirds there are

All that we need to do to read data into this array is to create a new song and use the `<BREAK>`s and newlines in the input file as delimiters to now which information should be listed as the song's title, etc. Newlines will be removed from the lyrics before they're read in to the Song objects.

Since this approach simply involves scanning and copying data without any sorting or structuring, it should go pretty quickly. We then create a temporary array to store matches.

## Searching Data

Searching data is easy, too! Simply go down the array and for every song in the list, search the lyrics string for the word we're looking for. (Passed through the capitalization and punctuation scrubbing function, of course.) Every time we find an occurence of the word, increment that song's counter, then copy the song into the temporary array. (This means the same song can be copied multiple times). When we hit the end of the song, reset the song's counter so we don't get messed up on the next search.

### Copying songs

This is already a pretty memory intensive algorithm, so the last thing we want is to store the entire array a million times if we hae a search term like "the". So, we simply search the file for all occurences of " ". Since searching for the word gave us the index of the occurence, we can simply only copy over a substring of the song's lyrics, from 5 space indexes before the word to 5 space indexes after. The new song in the temporary array will then only have 6 words.

### String Searching

Of course, the viablity of this entire algorithm rests on the ability to sort strings in non-linear time, because we sort strings A LOT. The way we cut time off searching is by using an algorithm to search that doesn't look at every character in the string. We can use some simple logic rules to determine how far we can jump forward if certain elements of the pattern don't match, basically making the string a hash table. For example, if the current `char` isn't in the pattern we're searching for, we can jump forward by the entire length of the pattern. There are other logical rules that should exist as well. For example, if a pattern does match, but the whole apttern does it, we can just jump forward to the point where an earlier occurence matches as well. Using rules like this, we should be able to skip huge potions of the string we're searching and get the thing done in close to logarithmic time, which would let us do all this crazy searching.

EDIT: After searching around on the Internet, it looks like 2 researchers named Robert Boyer and Strother Moore did exactly this. (http://www.cs.utexas.edu/users/moore/publications/fstrpos.pdf)

## Sorting Data

We can just sort the Song objects with a quicksort. It shouldn't put any noticeable drain on speed, since each song is now only 6 words long, so copying isn't an issue.

## Presenting Data

Just go down the temporary array and print the title, artist and lyrics of the song. Once we've gotten to 10, or if we reach the end of the array, stop and delete the temporary array.

## Exiting the program

We'll have to remember to delete the main array when the program exits.
