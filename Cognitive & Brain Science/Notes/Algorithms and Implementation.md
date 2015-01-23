# Algorithms and Implementation

Last week, we discssed different levels of cognition and problem solving, from the computational (what's the problem?) to the algorithmic (what's the software?) to the implementation (what's the code?). In the past, there was a very weak link between cognitive psych and neuroscience. Experiments were difficult and imprecise, and we didn't know how the hardware and the software of the brain interacted. With the advent of computers, the gap becan to narrow, and now that we have brain wave sensors and MRI's, we can actually see what's going on in there. In the 80's, fMRI's gave us access to blood flow and brain activity. More recently, DTI shows us patterns of neurons firing, as well as direction. TMS zaps the brain with an EMP, which disrupts neurons firing. You can then see how the test subject is impaired. **NEVER PARTICIPATE IN THESE STUDIES. THEY HURT.**

So what's the relationship between the mind and the brain? We know that cognitive behavior is made of many small, basic functions. Problem is, we don't know how they work together. Obama advocated for mapping the human brain during his campaign, but at this point, something like that would take centuries, and all the fancy behavioral data in the world isn't going to help us. We do understand small things, though. Basic functions are carried out by specific reigons. This approach has led many researchrs to seperate the brain into "modules", each of which does one thing, and one thing only. We don't know if a module is located in one space, or working on some sort of "virtual machine" running throughout the brain. So, let's talk about one! The first person who tackled this problem was a man named Paul Broca, who was a neurologist in the 1860's, which meant he had no real means of testing, except on accident victims. After observing them, you could then autopsy their heads when they died. The first patient was a guy who could only say one word. "Tan".

![](../res/hodor.png)

Hehehehe. Anyhow, when Tan died, it turned out he had a cyst in his left hemisphere. after observing 8 similar cases of aphasia, he found 8/8 cases in the left side of the brain. Hmmm...

Before we continue, we need to know that your brain is split into two sections. Since your eyes are concave, and the image is switched around, the left side of your brain controls the right side of your body and vice versa. This speeds up processing time because the hemispheres don't have to bus data to each other. Data is bused through one connector only, a web of neurons called the *corpus callosum*. So if our language module is running mainly on our left side, we should be able to test it on normal people. We can do this with a simple test. If we flash words quickly enough for our eyes not to be able to move, we do see that words picked up by the left hemisphere (on the right side of the screen) are far more accurate! The final pice of evidence that language lives on the left side is something called *split-brain research*. This was a briefly used (somewhat effective) surgery technique for people with epilepsy. Seizures are basically short circuits in the brain. This causes undesied operation, and the person spazzes out. When epilepsy gets to the point of last resort, and we resort to surgery. One approach that was used was to sever the corpus callosum, making the left and right sides autonomous. The good news is that the patients were 100% fine! Other than some obvious and expected coordination issues, the seizures went away and the patients seemed to go back to normal. However, there's a problem when only one hemisphere gets information. Obviously, this is rare, but in the lab, we can engineer these situations to see what the hemispheres of the brain are doing. When only the left hemisphere gets information (in this case, a picture of a spoon), the patient sees a spoon. When only the right hemisphere gets it, the patient doesn't see anything. But, when we ask him to find the object he didn't see by touch alone, he finds the spoon. (And probably gets freaked the hell out.) SO, only the left brain can say it, but only the right brain can find it! Clever, right? So we know that language is proccessed on the left side of the brain.

To be super clear that this is language, and not speech sounds, this experiment works on deaf people, too. But as far as we know, languae happens "somewhere on the left side". More detailed study of more patients help us narrow Broca's area down to there the frontal lobe meets the tempral lobe, near the Motor Control and Sensory Strips, which pass right through it. This corroborates the idea that aphasiacs can comprehend things fine, but can't generate speech. Let's watch a video!

...Jesus, this is depressing.

Broca's aphasia has a cousin, Wernicke's aphasia, near the parietal lobe, away from the motor area. This is the oposite of Broca's aphasia. People with this never shut up. They have perfect grammar, but their speech makes no damn sense. They freely invent words and recite lists of numbers, but they have no comprehension at all. Let's watch another video!

...Holy shit, this is awful. I feel like I'm on the subway.

As depressing as these 2 videos are, we can pinpoint specific language functions. If we do some mroe research, we can see that Broca's aphasiacs can perfectly understand sentences like "Equestria has 4 princesses, one of whom was a unicorn." If we simplify the sentence to "Equestria four princesses one unicorn", or even "Equestria 4 princesses unicorn", anyone with even basic understanding of MLP can figure out what the sentence means. And Broca's aphasics are fine with this. But have a sentence like "The alicorn Twilight turned into, as opposed to the unicorn she was, is tall". (Which is virtually incomprehensible to Broca people. It's as if they only see "Alicorn", "Twilight", etc, not the connectors. So Broca's aphasiacs have toruble with *syntax*, while Wernicke's aphasiacs have trouble with *semantics*.

So, we know that the brain is divided into modules. But what do they do?

* Does **language** deal with syntax or semantics?
* Does **vision** deal with faces? Objects? Everything?
* What if you want to tweet? Where does that go?

The jury is still out on how far we should subdivide and how much modules communicate. There are 2 main types of theories.

### Type 1

These theories decompose coginition into a theory of Computation and the Algorithms that perform them. (Making words out of sounds)

### Type 2

We can't decompose thee. The system under analysis is the simplest description we can get, and we can't go any further. (Predicting the weather)

We really want a Type 1 theory. The problem is, all we have to understand the brain *is* a brain, and we might never get to that level of understanding. Regardless, there are 2 approaches to cognitive proccesses, and we can see these all accross CS. (Which one our brain runs on, well, we're not sure...)

## The Symbolic Approach

The mind is a *symbolic machine*. Is represents the world in **symbols**, and manipulates these symbols with **rules**. This should sound familiar to you; it's also the driving principle behind Lisp and that entire branch of AI development, and to a lesser extent, Haskell and functional programming. And of course, later, this forms the basis of the C family. This is a bottom-up process. We recognize the letter, find a match in out lexicon, and then look up the meaning. We find valid sounds, put together the sounds in ways that sound right to us and might have meaning. ("Dax" is much nicer looking than "Xad", unless it's the '90s.) We know how to extend those rules. (The plural of siff is siffs) We also know how the words go together. "The dog barked and chased the cat." is much better than "Barked and chased the cat dog the."

Our brains are also capable, therefore, of using logic as the basis for all thinking. So, let's try!

> Parasprites are back and we need all the Unicorns' help in one place to get rid of them. You have a list of all the Pegasi and all the Unicorns within 100 miles of Ponyville. You also know who's in Canterlot and Cloudsdale. In order to make sure all the unicorns are in Canterlot, whic two lists do you need to look up?

Chances are you knew you needed the unicorns, but don't be fooled! You don't need Canterlot! All you need is Cloudsdale, so you can check if the lists are mutually exclusive! And that's something your brain knows at its base, according to this approach.

### Vision

As humans, we also have no problem finding edges. Hell, if we cross our eyes enough, we can register infintesimal shifts in those stupid magic eye drawings! So, why can't computers do it? This is a huge hole in cognition with this approach. We should simply be able to find the symbols and the rules, but we can't with computers yet.

So, let's start with a system that actually works. Ours. We've extensivley mapped the optic system, and we can track an image as it comes in. Photoreceptors detect light, and fire up ganglia in the center of the retina, which sees basic contrast. The center of the ganglion increases the chance of it firing when light is shone on it. The periphery has the opposite effect, which means that the ganglion only fires when it sees contrast, in the event of an edge. Some of these ganglia work the other way, but either way, these provide the basic data readings. The contrast data then goes to "edge finders", which put these "spots" from the ganglia together to find "bars". And so on and so on, we work our way up through levels and levels of abstraction.
