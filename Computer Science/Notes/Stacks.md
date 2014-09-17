# Stacks (on stacks on stacks)

## Unix Tip of the Day

There are 2 programs you should know, BC and DC.

### BC

It's a calculator. But it doesn't throw weak-ass overflow messages. Take that, '90's calculators! Something written in the '60's kicks your ass! For a lot of digits, call `bc -l`. For enormous amounts of digits, set `scale = 1000` or something.

### DC

DC came before BC, but the syntax is a lot more cryptic.

## Stacks

![Computer Science, Bitch!](../res/Stacks.jpg)

A stack is an abstract data type. Remember that this means that it defines operations without any specific way to handle the information. Today, we'll be using a dynamic array as the underlying data structure, which is much easier to work with.

Think of a stack as an array, tipped on its side. There are three basic options:

* You can look at the entity on the **top** of the stack, but not change it.
* You can **push** an entity on top of the stack.
* You can **pop** an entity off the top of the stack.

Of course, this is the bare minimum. You can also include functions to see if the stack is empty, pop everything off until it's empty, etc. Because only the top element is available to us, stacks are called *LIFO* structures, Last In, First Out.

Despite these limitations, stacks are very frequently used. Most computer architectures use stacks at the core of their instruction sets. Pushes and pops are at the core of ASM and machine language. There are also stacks built into every program on your machine. The stack is a memory block that gets used to work with functions and variables. This is really low level; even C doesn't usually go near the stack unless you're Linus Torvalds or something.

### Why do we use stacks when functions are called?

Let's say we have a bunch of nested function calls:

```c++
main()
{
	f1();
	return;
}

f1()
{
	f2();
	return;
}

//and so on and so on
```

Notice anything? When we work our way up through the returns, we're going through these functions in the same Last In First Out order that stacks are so good at. In fact, this was the first use of stacks, proposed by none other than the great founder Alan Turing himself. (Although he called push and pop *bury* and *unbury*, because he was British and that sounds classier.)

### Efficiency

Stacks are so simple, we can implement them by simply limiting the functionality of a dynamic array. By setting the top of the stack to be the end of the array, we can get a constant time efficiency. Not bad!

How about a linked list? We can push and pop on either the head or the tail (head is usually a better choice), and we still get a constant time efficiency.

Finding stuff in a stack, however is really difficult, and preseving the data you're digging through gets really nasty. If you need to search or use random access in your data you shouldn't be using a stack because it's simply impossible to walk through.

### Example

Here's some sample code from Lab 1:

```c++
if(temp == NULL)
	{
	return false;
	}
for(size_t i = 0; i < pirateCount; i++)
	{
	temp[i] = hbook[i];
	}
```

There are a lot of brackets here, including some unneccessary ones. We can use a stack to determine if these brackets are properly matched. Add openers to the stack. If a closer matches the item on top, pop off the opener. If the closer and the top opener are different, however, we can just fail right away. If the stack is empty, we're good. If not, we're in trouble.

The asymptotic complexity of this algorithm is linear, thanks to the stack's constant efficiency.

## Reverse Polish Notation

Remember BC's cryptic syntax? It's actually something called Reverse Polish Notation. This notation is the reverse of one thought up by some Polish guy who could into math. In RPN, you put your operands first, followed by the operation. You can nest files this way:

```
>3 4 +
7

>4 5 6 + *
4 (5 6 +) *
4 11 *
44
```

![Can into math!](../res/Polan.gif)

A stack is a perfect way to evaluate RPN. Just read the input and push numbers on the stack until you reach an operator. When you see an operator, apply it to the first 2 numbes popped from the stack. Push the resulting value back on the stack. When the input is complete, the value left on the stack is the reuslt. None of the PEMDAS order of operations bullshit. In fact, the first programmable desktop computer ran its math and functions off RPN.

Good on you, Poland. Maybe you will someday into space.
