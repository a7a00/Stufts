# Pattern Recognition

The reason we're talking about symbolic approaches and all that jazz is something called *pattern recognition*, and this is the holy grail of cognitive science, everything from computer vision and AI to neurobiology. So, to start, what is pattern recognition? An accepted definition:

> Pattern recognition is a process whereby a perceptual event is compared to prior experiences and categorized as belonging to a particular type of object, state, etc.

Or, a better way to express it:

![](../res/otter.gif)

So, we know that the brain has many diffrent modules, each of which take input and produce output. Remember Type 1 and Type 2 theory from last week? Let's revisit Type 1. THis theory just says that the mind uses set rules to manipulate set symbols, like what we do when we code. Remember that this is *bottom-up*. So we recognize shapes, find matches to letters, find matches to words, find matches to meaning, etc.

When we try to do this with vision, we do something similar. We find the smallest unit, build patterns, etc. Last lecture, we got up to ganglia, which can recognize contrast. To get to the next level, which is edge finding, we need to know about what's going on in the primary visual cortex, located in the Occipital Lobe. So, how did people find this out? The function was discovered in 1962, by Hubel and Wiesel. Methods like MRI and TCS are crude at best, but we're not limited to these crude and humane methods when we use... CATS!

![](../res/pusheen.gif)

So we anesthetize the cats, show them pictures of basically random shit on a screen, and scan what's going on in their heads using a very painful microelectrode, but whatever, it's a cat. No matter what they tried, though, the cats didn't give a shit. (Well, they are cats...)  After months and months of trying, they found their breakthrough by accident. As they were pulling the slide *out* while the light was still on, the cells in the Primary Visual Cortex went nuts. After further experimentation, they found that most of the cells in there detect straight lines. That's it. Some detect vertical lines. Some detect horizontal lines. Some detect 45 degree lines. Some detect 156 degree lines. That's it. That's all they do. And of course each line detector is basically made of a stack of ganglia. See how we're working our way up?

![](../res/fromthebottom.gif)

God, my jokes are awful. What's important to remember is that these aren't all edge detectors. Since some have firmware that detect color and motion, most neurologists refer to them as *feature cells*

This works with people, too! We just played a game showing that that I can't type out, but basically the gist is that finding a simple red thing takes constant time, as does finding a simple horizontal thing. Finding something both red *and* horizontal requires cells to talk to each other, giving us a *linear* search time!

## Gestalt Principles

These are basic rules that our feature cells follow to group things once we have lines, that were found in the 1920s and '30s in Germany. These are:

### Proximity

```
|| || ||
|| || ||
```

We see 6 lines at first, not 12.

### Similarity

```
XXXX X*X*
**** X*X*
XXXX X*X*
**** X*X*
```

We see rows on the left, columns on the right.

### Smoothness
```
\__/_
 /    \
```

We tend to see curved lines intersecting as 2 lines, not 4.

### Closure

We can identify:

```
---- -----
```

as one line, not 2.

These rules are the basic symbols that allow us to put together objects! Makes perfect sense, right?

Unfortunatley, like most scientific endeavors Germany funded in the 1930s, there's something really wrong with the Gestalt rules. And that is, where do we draw the line? When do we decide "OK, we found the letter?" Look at this:

```
    /    \ 
   /      \
  /--------\
 /          \
/            \
```

Is that a shitty "A", or a shitty "H"? Because if we put it between a "C" and a "T", I'd see an "A". A "T" and an "E"? You'll see an H.

However valid the Gestalt rules are, here's clearly something more than a strict, rules-based approach.

![](../res/hitler.jpg)

Sorry, Germany. You were only half-right here. (Although, given what else you were up to in the '30s, that ain't bad.)
