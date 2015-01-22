# ReadMe for COMP 15 HW6 - Song Search 

## Purpose

This program searches a properly formatted input file, returning all the occurences of a given word in the 10 songs where that word appears most frequently. Punctuation and capitalization are ignored.

## Algorithm

### Reading in Data

First and foremost, a fast loading time is important. This algorithm does almost no preprocessing, simply reading in the title and artist into a new `Song` object and reading the lyrics in as one long string. No further structuring is done. As a result, we can achieve a loading time up to 1/10th the length of comparable algorithms.

### Searching for Data

Because every string has to be searched for every word, this program uses a log(n) string search to keep search time low. (See the subsection for more details). Each string of lyrics is searched 3 times, once for "pattern" (all lowercase), once for "Pattern" (properly capitalized) and once for "PATTERN" (all caps). No other capitalizations exist in the input file, which means no data is lost. The pattern is scrubbed of any punctuation before being searched for. Whenever the string search returns the index of a match, a new song is created in a vector of matches, containing all the same information, but with a higher match count and only the context inserted as its' lyrics. (6 spaces before the index to 6 spaces after gets us 5 words on either side.)

#### Searching Strings

The pattern to be searched for is buffered by two wildcard characters (In this case, we use `ASCII 17-Device Control 1`, which would not appear in an input file.) to prevent against partial matches, like finding `Shy` in `Fluttershy`. We then preprocess the search string, creating a table of values for every index in the table using an algorithm similar to those used in hash functions (so constant time) that tell us how far ahead we can "jump" without possibly missing the pattern. We then start at the end of the pattern and work our way back, sending the index for copying if we reach the beginning of the word. If we hit a mismatch partway through, we can just look in the table and see how far we can jump. This means we don't have to look at every element in the string, and we can just hop along at log(n) speeds. Neat, huh?

We run into a small problem, though. Wildcard matching can help us not worry about punctuation at the beginning and end of the pattern, but what if we have a situation like this? (`$`'s are used to represent wildcards.)

```
 TEST-PATTERN 
 $TESTPATTERN$
```

The second wildcard matches with the space, but since we;re supposed to ignore punctuation, how can get these two to match up? Simple! If we see punctuation, simply hop the search pattern *backwards* one space! That gets us:

```
 TEST-PATTERN 
$TESTPATTERN$
```

And we can match the beginning of the file and return the index for it. We then have to remember to bump the index back up one so we're not caught in an infinite loop!

**THIS PART OF THE CODE IS CURRENTLY BROKEN. THE INITIALLY PROVIDED VERSION WILL JUST IGNORE ANY WORD WITH MID-WORD PUNCTUATION. THE VERSION PROVIDED TOMORROW WILL HAVE THIS WORKING.**

### Sorting Matches

Based on the way the matches vector is populated with songs, any song added will contain the amount of times a match was found in it, not the frequency. This results in a vector of matches with counts that look like this, with the pipes separating songs with different titles.

```
1 2 3 4 | 1 2 | 1 2 | 1 | 1 | 1 2 3 | 1 2
```

Finding the 10 highest frequency songs is therefore quite simple. Find the song with the biggest count in the vector and lift it and the `count-1` songs before it into an vector of sorted matches. Remove that chunk from the matches vector and repeat 9 more times. You can then go through and print all the songs in the sorted matches vector.

## Files

`songsearch.cpp/h` - Methods and associated headers neccessary for loading and searching the database.
`main.cpp` - Runs the program, reading input from an appropriatley formatted file.
`Makefile` - For compiling.

## Compiling

`cd` into the directory and type `make songsearch`. Provide the properly formatted file you wish to search as an argument to the executable created.

## Acknowledgements

A huge thanks to the TA's of Halligan, especially Anna Kaplan, who stuck with me through my ill defined ranting about what the program was going to do, to my angry ranting about bugs, to my stressed ranting about conceptual mistakes. You have the patience of a saint. More thanks goes out to [TJ Horner](https://github.com/tjhorner) of Carlsbad Middle School for helping me with nightmarish 11th hour debugging, even while he had homework and high school prep to do and sites to maintain. An enormous thank you to Professor Gregg, who entertained my strange algorithm ideas and agreed to meet with me to discuss my code *after* the due date. Props to the helpful users of StackOverflow for helping me figure out exactly how to make my algorithm effective. And of course, [this](http://www.cs.utexas.edu/users/moore/publications/fstrpos.pdf) paper for all the information on log(n) string searching.
