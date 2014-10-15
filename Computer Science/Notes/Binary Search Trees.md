# Binary Search Trees & the ""Big Three"

## A note About the Auto-Grader

The auto-grader will print out the source code of tests you fail. DON'T USE THE AUTOGRADER TO TEST YOUR CODE. Seriously, it's horrible practice and you need to write your own tests.

There will be a restriction on the auto-grader next assignment.

Also, not commenting you code will result in a penalty.

## The Midterm

The average on this test was an 87, and you got a 95! Yay! How does it feel to be above average again? Suck it, senior year, Gould is back in the saddle! Anyhow, this class needs a lot of practice with recursion and linked lists. If you think your exam is screwy, submit it for a full regrade. No partial regrades!

### On the military question

Yeah, I'm not posting these jokes here...

## HW3

Fewer memory leaks! But you guys need to learn what copy constructors are...

## The "Big Three"

Lots of you think that `tempqueue = queue` is acceptable. It's not. Either you're messing around and pointing to an array that's been modified in a way you don't want, you're getting a `DOUBLE-FREE` or you're segfaulting. In order to do this *properly*, you need one of  3 things:

### Destructor

This just cleans up resources.

### Copy Constructor

This creates an entireley new instance of a class and copies over the old copy to the new one.

### Assignment Overload

This copies one class to another copy that was previously created.

See handout for full code. I'm running on 2 hours of sleep, I can't keep typing.
