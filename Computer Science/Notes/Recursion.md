# Recursion

Full notes available [here](./recursion.md).

## Piping and `diff`

You can use the ">" symbol to pipe output from one file to another:

```bash
./program > file1
```

You can use the "|" symbol to pipe output to another program.

```bash
fortune | ponysay
```

The advantage of piping out to files is that you can use the `diff` command to compare your output with an ideal output file you might be getting some time in the future.

## Recursion

All recursion means is that a function calls itself.

*NOTE: IF ANY OF YOU JOKERS CALL MAIN() IN MAIN(), YOU ARE GOING TO BE IN BIG TROUBLE, AND I DON'T MEAN WITH THE COMPILER*

Let's look at a real life example. Let's talk about solving a jigsaw puzzle. If the puzzle's finished, we stop. If not, place a piece in.

Recursive programs can always be expressed as loops. The only reason we do it is because it's more elegant and simpler to code.

Recursion is always implemented te same way:

* Check for the "base case", which is the signal to stop recursing.
* Work towards the solution a bit.
* Recursively call yourself.

### Counting from N to 0.

We check if N is less than 0, print N, and then count down from N-1.

```c++
void countDown(int count)
{
	if (count < 0) return;
	cout << count << "\n";
	countDown(count-1);
}
```

Note that we can't just sub out a plus and count up. There isn't a nice base case like 0. So how do we solve the problem? Well, one option is to have multiple parameters. In addition to count, we could just have a maximum and pass that down the line without changing it. Or we could do this:

```c++
void countUp(int count)
{
        if (count < 0) return;
	countUp(count-1);
        cout << count << "\n";
}
```

This approach doesn't print anything on the way down. It prints after the recursive call on the way back up. Simply by changing just one line, we've reversed the order. Such is the power of recursion.

So what are some other uses of recursion? We could use it to walk linked lists (assuming a tiny list). LISP and Haskell have a particular penchant for tail recursion. Some other common (but inefficient) uses:

### Exponents

a<sup>b</sup> = a*(a<sup>b-1</sup)

```c++
double power(double b, int n)
{
	if(n <= 0)
		return 1
	else
		return b * power(b, n-1)
}
```

### Factorial

n! = n*(n-1)!

```c++
long factorial(int n)
{
	if(n <= 1) return 1;
	return n*factorial(n-1);
}
```

### Fibonacci

Let's look at the retarded way to do it:

```c++
int fibonacci(int n)
{
	if(n == 0) return 0;
	if(n == 1) return 1;
	return fibonacci(n-1) + fibonacci(n-2);
}
```

This implementation looks pretty, but is actually really, really stupid. Not only does this amount of recursive calls eat up your RAM, it also has exponential complexity and neccesitates repeated work, which makes it a really shitty way to find the next number in a sequence.

Now let's look what happens when we add a helper:

```c++
int helper(int n, int p0, int p1)
{
	if(n == 1) return p1;
	return fibHelper(n-1, p1, p0+p1);
}

int fibonacci(int n)
{
	if(n == 0) return 0;
	return fibHelper(n, 0, 1);
}
```

By passing up this extra value, we don't have to do any of the extra work to get the answer.

### Greatest Common Divisor

There are many ways to do this. Let's look at a few:

#### Brute Force

Start at the smaller number and count down by 1, trying every single number until we find one that works.  We don't even need to implement this, we know it's horribly inefficient.

#### Euclid's Algorithm

```c++
int gcd(int x, int y)
{
	if(y == 0) return x;
	return (gcd(y, x%y));
}
```

The proof of why that works can be found [here](http://goo.gl/p9JtRo).

### Palindromes

Just see if the two letters at the ends are the same, and then evaluate the substring created by lopping those two letters off. Sort of a "middle-in" approach. You reckon this would work for "data" manipulation, Richard?

![Silicon Valley](../res/PIEDPIPER.gif)

(Code available on the course website.)

## Important

We watched an adorable dog video today.
