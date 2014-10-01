# Binary Trees

## Unix Tip of the Day

Cowsay and say are really funny when you give them to this class.

## In-Order traversal

This entire part of the lesson was basically more work with our algorithm, go left, print, go right, return.

Just get the animations [here](http://nova.umuc.edu).

## Binary Search Trees

These trees are good for searching because as you go through, you cut the problem in half a lot, which gives you logarithmic complexity. These trees have an invariant that must be true at all times. For every node, all the elements in the left subtree must be less than that node, all elements to the right must be greater. If this condition isn't met, it's not a binary search tree. Since each layer is double the one before it, the depth of the tree is logarithmically dependent on the number of elements in the tree.

### Functions with Binary Search Trees

Finding the minimum is easy. Just look at the leftmost left part until you hit null. The smallest element is always on the left. Complexity: log(n). Finding the maximum is also easy. Just go right instead.

Finding if there's a value in the tree can be done recursively. If the value of the node is what we're looking for, return true. Then recursively call to the left or the right depending on if X is smaller or larger than where you are. Inserting is the same thing, but you need to find where the number is SUPPOSED to be. Then add the node. If it's already there, just mark that there are now 2 x's in the tree.

Removing a node with no children is easy. Just nuke it. Removing a node with one child is pretty much deleting from a linked list. But removing one with 2 children is tricky. Replace the node with the smallest data in the its subtree and recursively delete that node, which is now useless.

### Tree Problems

How do we find the size of a binary search tree?

```c++
int size(Node *node)
{
        if(node == NULL)
                return(0);
        else
                if(node->lchild == NULL && node->rchild == NULL)
                        return(1);
                else
                        return(1 + (size(node->lchild) + count(node->rchild)));
}
```

Prof. Gregg says gr8 b8 m8 r8 6/8 could be simpler.
