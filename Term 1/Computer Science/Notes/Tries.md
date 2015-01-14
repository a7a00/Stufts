## Balanced Trees

A balanced binary search tree is one with a condition that's easy to maintain and ensures logarithmic complexity. Basically, for every node, the left and right subtrees are the same length. Note: this means *every* node. This is unfortunatley too rigid, and only allows for full trees, which rarely happen. So to solve this, we have...

## AVL Trees

It's the same as a biinary search tree, except that for every node, the height of the left and right subtrees can only differ by 1. Remember that the height of a node is the distance from that node to its lowest descendant!

So how do we make an AVL tree out of a non-AVL tree? (This is common when we insert something.) The answer is something we call *rotation*.

### Outside Cases

This is if we're dealing with the left child of a left node, or vice versa. Let's take a look:

```
           K2
          /  \
         K1   Subtree Z
        /  \                        
Subtree X   Subtree Y
```

X has depth 2, lets say, and Y and Z have depth 1. THis means the root is out of balance, since K1 has depth 3 and Subtree Z has depth 1.

We fix it by going to the child with the greater depth, and through some process that for the life of me I do not understand, the tree becomes this.

```
      K1
    /     \
Subtree X  K2
          /   \
     Subtree Y Subtree Z
```

Use [this](https://www.cs.usfca.edu/~galles/visaualization/AVLtree.html). It'll help.

### Inside Cases

This is where we're dealing with the right child of a left node, or vice versa. Single rotation doesn't work, so we need something called double rotation instead.

Jesus, it's more confusing than the first one. Use [this](https://www.cs.usfca.edu/~galles/visaualization/AVLtree.html) with the sequence `3 2 1 4 5 6 7` to see single rotation and `16 15 14 13 12 11 10 8 9` to see double rotation.

##Tries

All right, this is something extremley cool. Carrie does it. Chary does it. Everyone does it! So, let's go over what makes binary search trees so special. They have logarithmic complexity, even with this wacky insert stuff. But still, let's say we have a binary search tree of words sorted alphabetically. Problem is, we're likely to get really shitty cases because they have similar prefixes. A lot of words share the same beginning letters, which means we'll have to do a lot of climbing. So how do we do better than a complexity of log base 2. We could make a terenary tree and have log base 3, but that's not fun. How about we make each LETTER a node? Like this?

```
     P
    /\
   L  O
  /\  /\
  A O M N
 /  | | | 
 N  T F Y
/ \ | | |
T * * * *
|
*
```
"*" denotes the end of a word. Pony plot plan? Pomf!

![Aww...](../res/Fluffle_Puff.png)
