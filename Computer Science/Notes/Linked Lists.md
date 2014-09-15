# Linked Lists

## HW1

No, your homework isn't graded yet, because it needs to be checked manually. The results should be back to you by next Monday.e that.

## Pro Tipz for 1337 MLG Haxx0rz

The department makes a backup of your files every hour, and puts them in a hidden directory called `.snapshot`. You should us.

If you're running out of memory space on the server, use this simple bash script to get out of the woods (Eclipse hoards data)

```bash
bash
for f in core javacore Snap ; do
find . -name $f\* -exec rm {} +
done
exit
```

## Linked Lists

Linked lists are slow, balky, horrendously disadvantaageous, and virtually useless in real life, but they're a really easy example of data structures to teach. So we're doing them. Anyhow, linked lists are made of nodes. (Not frontends for JS.) A node contains some information and pointers to its neighbors. Unfortunatley, this means that memory can get fragmented. This is a nightmare for linearly arranged memory, and makes caching difficult. Copying blocks of memory from RAM to an even faster cache makes your computer run quickly, and linked lists make caching data an absolute nightmare.

### Structure

Linked Lists always have what's known as a head and a tail. The head is *not* the first node. It's a *pointer* to the first node. Each node has a pointer to the next node. Simple enough. The tail of a linked list always points to `NULL`. That's how we can tell we've made it to the end of the list. Remember that the tail node NEVER contains a null pointer.

We declare a node like so:

```c++
struct Node
{
  someType data;
  Node * next;
}
```

See? Not too bad at all. We can just use this structure to stroll along the list like this:

```c++
node * current = head;
while (current != NULL)
{
  if (/*test on current*/) break;
  current = current -> next;
}
```

### Removing a node

If we're going to remove a node, we need to keep a pointer to the previous node. That just needs a few extra lines of code:

```c++
node * current = head;
node * prev = NULL;
while (current != NULL)
{
  if (/*test on current*/) break;
  previous = current;
  current = current -> next;
}
```

Removing it is somewhat lengthy, but easy enough to understand:

```c++
void removeNode(Node * n)
{
  Node * current = head;
  Node * prev = NULL;
  while (current != NULL)
  {
    if (current == n)
      break; //or update
    prev = current;
    current = current -> next;
  }
  if (current != NULL)
  {
    if(prev == NULL)
      head = current -> next
    else
      prev -> next = current -> next;
    delete current;
  }
}
```

All we're doing in the above code is breaking the links and reattaching them so that the two neighbors are coupled. Since the one removed is no longer being pointed at by anything.

Remember to draw out the situation! It helps a lot!

### Inserting a node

Pretty much more link reassigning. Push the new one in and link it up in the chain.

```c++
void insertNodeAfter(Node * n, Node * newNode)
{
  if(head == NULL)
  {
    head = newNode;
    newNode -> NULL;
  }
  else
  {
    Node * current -> head;
    while(current != NULL)
    {
      if(current == n)
      {
        newNode -> next = n -> next;
        newNode -> prev = n;
      }
    }
  }
}
```

Inserting from the head is in constant time. You just tack it on. However, interting at the tail is linear because you have to slog through the entire list before you can do the insertion.

### Searching a linked list

We've already done this. Worst case scenario is linear, best is constant. For reasons why, see above. There is no way to perform a binary search on a linked list by definition. Don't try.

## Doubly Linked Lists

Nodes in these lsts have both forward and backward pointers. They're more efficient, but they can get really ugly.

## Circularly Linked Lists

The tail points to the head. No nulls, makes walking easier. Give and take. All right, looks like we're done.
