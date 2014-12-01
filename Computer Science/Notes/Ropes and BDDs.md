# Ropes & Binary Desicion Diagrams

## On the Final Assignment

There's now a version on the CS site theat actually works so you can debug! It's at /songsearch_web in the public HTML directory, so you can just hop on [in your browser](http://www.cs.tufts.edu/comp/15/songsearch_web/) and see how badly you're screwing up. Also, provide is up. Get cracking.

## Ropes

Most strings are stored in memory in contiguous array-like chunks. Ropes break down strings into binary trees, in which the text is always held in the leaves. Walking through the tree prints out the string. Each node contains either the number of characters in it (if it's a leaf) or the sum of its left subtree.

I missed a lot of this because I had to document a problem in songSearch that I'm going to have to fix later.

Anyhow, ropes are cool. They're like funky non-distributes strings.

## Binary Decision Diagrams

These are based on Boolean functions, which are the cornerstone of CS, cryptography and EE. These are functions that represent "true" as 1 and "false" as 0. They're really simple at the outset, but they can blow up exponentially. There are 16 ways to represent 2 variables in a boolean function. Some of these are `NAND`, `XOR`, `ALLTRUE`, `NOR`, etc, and some others don't have specific names. For any `n` variables, there are `(2^(n^n))` possible boolean functions. That's a bit many.

BUT, there's a trick! All functions can be made of NAND's. `NOT A` is `A NAND A`, `A AND B` is `NOT (A NAND B)`, or `NAND (A NAND B) (A NAND B)`. Since `NAND` is made of `NOT`, `AND`, and `OR`, we can limit all operations within our machines to these 3 operations.

A standard boolean function is written `!x1!x2!x3 + x1x2 + x2x3`, and is read `(NOT x1 AND NOT x2 AND NOT x3) OR (x1 AND x2) OR (x2 AND x3)`, where `x1`, `x2`, and `x3` are boolean variables. The solution of course depends on their initial values. The order of operations is usually `NOT`, `AND`, `OR`, although some processors might work differently.

But these functions can generate massive amounts of possible solutions as soon as the amunt of variables even gets slightly large. How do we represent these functions without taking up too much space? The answer is a Binary Decision Tree. Each node is a question. (Is this variable true or false?) so all we need to do is start at the root and look at each variable and work our way down the tree. We can save space by merging identical subtrees. We can then stop making copies of 1 and 0 and just start pointing to one loaction where we have the thing stored. Repeated merging gives us a highly compressed tree.

Professor Gregg explains this better [here](http://www.cs.tufts.edu/comp/15/lectures/Day_23/Day23.pdf) and [here](http://formal.cs.utah.edu:8080/pbl/BDD.php).
