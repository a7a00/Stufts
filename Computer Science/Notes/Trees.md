# Trees (Duuuude...)

## Late Assignments

I don't care if you provide assignments a few hours late. Just ask me for permission beforehand. If I don't hear from you prior to the due date, you FAIL. Oh, and there aren't any TA's Friday nights.

## Using Valgrind

I'm not writing down how to use Valgrind because I'm too busy trying to find a gif of Snoop Dogg for a horrible joke. Basic gist of it is that there's Valgrind functionality built into Eclipse in an output tab.

Somehow we're 15 minutes into class and we're still fighting about how to do a project due on Friday...

## Trees

![SMOKE EVERY DAY](../res/Snoop.gif)

There. I made it.

Anyhow, for large amounts of data, linear data structures take way to long to search through. However, there's something called a "tree" that makes things much easier. The motivation behind a tree is breaking the problem in halves progressivley until we arrive at the answer. It's very simple to make. Simply start in the mddle and have two paths leading from each node. It's kind of hard to draw without TeX, but here we go:

```
A B C D E F G
```

Becomes

```
    D
  /  \
 B    F
/\   /\
A C  E G
```

So what is a tree? It's defined as a collection of nodes. There's a root node, and 0 or more sub-trees whose roots are connected by a direct edge from the root node. It's a very recursive definition. Trees use family notation (parents and children). Important to remember. If there are N nodes, there are always N-1 edges, because everyone has exactly one parent except the root. Childless nodes are called "leaves". We can define what we call a "path" from a parent to its children. The root can get to any leaf it wants, and we call that the "path". The depth of a node is the length from the root. The height of the tree is the length of the path to the deepest node. Nodes have anscestors and descendants.

### Implementing Trees

We could have each node link to each child, but this is infeasible because we have no idea how many children each node can has, Instead, we can use a LinkedList of nodes:

```c++
struct TreeNode
{
	Object element;
	TreeNode * FirstChild;
	TreeNode * nextSibling;
};
```

There's no need to keep track of all the siblings; instead, you have the parent give you the first child and each sibling down the line point to their next sibling. We can print files recursivley this way. (See file online)

### Binary Trees

Binary trees are trees in which each node has exactly 2 children. If there's ever a leaf not in a set of 2, it's a *complete* binary tree, not a *full* binary tree. The average depth of a binary tree is on the order of the square root of the number of nodes.

BUT! In order for a tree to be a complete binary tree, all nodes have to be as far left as possible.
### Degenerate Trees

Each node has only one child, so it's basically a linked list.

Sorry about the sparse notes, I'm still pissed that my samurai notes from this morning got nuked.
