# Decision Making and Language

Last time we talked about general approaches to problem solving and means-end analysis, as well as social problem solving and how chimps are assholes. Today we're going to talk about decision making.

## Decision Making

One of the fundamental problems with decision making is, of course, that we never see the whole picture. The world we percieve is a limited, simplified model of the problem space, so we don't act purely rational. We instead use something called *bounded rationality*, which requires a few things to work.

* A search rule, some way of comparing your options
* A stopping rule, which tells you when you have made your decision
* A decision rule, which chooses the optimal option
  * Minimalist decision rules choose based on random criteria. (We always use these the first time we make a decision)
  * "Take the last" rules choose based on whichever cue was most useful last time you made a decision similar to this. (This is useful when we've made the decision a few times before)
  * "Take the best" rules must evaluate which cue is most often the decising factor. (This is done when making this kind of decision is extremley common)

The more we make decisions, we will always narrow down our decision-making factors, and this is because the brain doesn't like an overwhelming amount of things to compare. This mans that as soon as we can think of something as not useful, we're more than happy to throw it out. This is a driver behind a famous part of psych and AI development.

### The Paradox of Choice

This is the phenomenon where more options leads to a worse outcome. If you give people too many options, they start to crash and burn. Case in point, how many times have you had 60 Japanese forums open trying to pick between a bajillion kinds of computers or cameras, and then ultimatley decided you didn't really need to buy any because the one you have is fine, or you'll come back tomorrow. (And you probably never come back.) We hit this tipping point where we crash and burn when our heuristics become insufficient to percieve a difference. Once there are too many things to choose from, they all start looking the same, and we're so terrified of the prospect of making a mistake, we just give up.

This paradox is a stopping rule problem, how does your brain decide when to stop decising and choose an option? As a general rule, we rely on heuristics, and usually take a good option when we see it. Since we can't rationally optimize a set so large, we often get stuck in an infinite loop when we try to find the best option. There are 2 ways we (and AI, in problems too complex for them, like chess) can get around this.

* Force yourself to grab the first option.
* Get out a pencil and paper and use it as "temporary memory", to give yourself the most rational decision making process possible.

Thre are generally 2 kinds of people, people who follow the first bullet point, like Dad, and people who follow the second, like Mom. An easy way to tell which kind of person you are is to answer the question "do you change the radio station to see if something even better is on?". People who follow the second option usually are far more succeptible to the paradox of choice, and, while they generally make hugher salaries, they also experience less satisfaction and more regret, often dreaming up other solutons to already solved problems. They also are very prone to thinking that the "grass is greener" and focusing on the elements of the outcomes that haven't improved.

Hey, Mom, you reading this?

Takeaway: Since the world in which we make decisions is far too large a problem space, we're forced to use heuristics, which can cause these problems.

## Language

All right, speaking! Languages are composed of 2 fundamental components.

* The **lexicon**, containing the meanings and sounds of words
* The **grammar**, containing how pieces of words combine together and what these combinations mean

### Behaviorism

Before Chomsky's work with language, people like B. F. Skinner called language "verbal behavior", and said that it was nothing more than a complicated habit. We make noises/draw shapes/hit buttons in response to stimuli. Grammar is simpy an association between sequences of words. Over time, we build up associations between words and other words, linking them together because we've heard them linked before. This association constrains the orders that we produce, which is why it's so counterintuitive to say nonsense.

### The Separation of Grammar and Meaning

Chomsky comes along and blows this shit out of the water with the followin sentence.

> Colorless green ideas sleep furiously.

This sentence is gramatical and causes no mental strain to read at all. But none of the words predict each other. So what gives? In addition, we don't just repeat what we've heard in the past. We say new stuff all the time, and it takes a lot more than a gut feeling to realize that the meaning you thought of for that sentence makes no sense. (You actually have to critically analyze it.) This means that language has to be generative. You can make new sentences all the time, which means grammar has to be seperate from the meaning of the words. As long as we follow the rules of grammar, we can say anything we want, no matter how weird the meaning, and it'll make sense. Grammar and vocabulary must be seperate.

Chomsly says that in order to define language, you need levels of representation (how do sentences fit together, how do words fit together, how do sounds fit together, etc.) and rules for how these can interact. As an example, "brick" is OK, as it follows all of these phonics rules, but a word that breaks them, like "mxyplyzyk" is awful, and you have to manipulate it in your head before you can even say it. The word "mxyplyzyk" is the phonetic equivelant of a jumbled up paragraph from the SHSAT. It makes no sense.

Some rules can be completley arbitrary and random. Sounds randomly match to meanings (and 4 year olds will not shut up until they store every new vocab word there is) some words cpmbine strangely, and 2 of the most common Japanese verbs, 来る and する, break EVERY FUCKING JAPANESE GRAMMAR RULE THERE IS. But for the most part, language is highly regular. All languages follow patterns for putting words together. In English, order decides what means what. ("the cat chases the mouse" vs "the mouse chases the cat") In Japanese, particles decide what means what, but order tends not to matter, so long as the acting word is at the end of the sentence. The grammar of the language allows us to take a finite amount of words and create infinitley long expressions.

### Syntax vs. Semantics

Every word has these 2 categories, syntax, representing the grammar, and semantics, representing the vocab. For example, you store each word in memory along with its part of speech and how it fits together with other words. We also have sample expressions. For example, a noun phrase is made of determiner*+adjective*+noun. (*'s denote optional components). Expressions can include other expressions, just like in a programming language. For example, a verb phrase is made up of verb+noun phrase*+prepositional phrase*.

#### Subphrases

Verb phrases, for example, are subcategorised based on which *kind* of verb phrase is acceptable beased on the verb. (Parens denote optional)

* Die: V+(PP)
* Take: V+NP+(PP)
* Put: V+NP+PP

As you can see, when you take meaning out of words, language is reduced to formal logic, and becomes an awful lot like... *math*. Oh, God! Of course, when logic shows up, there are loopholes.

* S: NP+VP
* NP: (determiner)+(adj)+noun
* VP: verb+(NP)+(PP)+(VP + S)
* etc, etc.

These rules allow for the creation of infinite sentences, if you look hard enough, and they can happen on the building words level, too! For example, we know how to diminuitize words, so we can instinctivley shorten "small self-portrait" to "selfie" and it doesn't sound weird at all! Neat, huh?

Subphrases aside, there's plenty of evidence that we build sentences these way on the fly. For example, have you ever accidentally said "Once I stop, I can't start." instead of the other way around? The reason your brain doesn't stop this is that you're building these grammar functions on the fly. Even though your memory farted and you grabbed the wrong verb, it still passes the "correct grammar" test and your brain gives it the go ahead to say as long as the slip happened between 2 structures of the same syntactical type. For example, you'd never accidentally swap a vowel and a consonant, or a noun and a verb, because your brain catches that. But, your brain works syntactically on the fly, which means that errors that are still syntactically perfect get through.

#### Garden-Pathing

We interpret language on the fly, too; we don't wait until the end of a sentence to start intepreting. So, for example, if we hear:

> I hit the lobster with the-

You'll expect a word like "stick". But if I give you a full sentence:

> I hit the lobster with the red fur.

You have to re-parse the *entire* sentence in order to realize that the lobster has the red fur, not me. This is called "garden-pathing". You're happily going along, putting together the sentence as I say it, and then all of a sudden you hit a wall, and have to go back and restart. Here's the mother of all garden paths:

> The horse raced past the barn fell.

This is an *awful* sentence, because it makes no sense, even though it's gramatically correct. The horse that was raced past the barn fell; what don't you get about that?

So what are these guesses based on? Well, there are 2 main explanations. The first is that we like the simplest structure possible. We'd much rather attach a new piece to a preexisting node, rather than create a new one. For example, we much prefer to intepret that "Rarity made that dress with the satin." as "Rarity made [that dress with the satin]", rather than "Rarity made [that dress][with(using) the satin].", just because the first intepretation is structurally simpler. And a lot of AI needs to simplify the sentences it parses and gtakes in to correctly read/convey the correct meaning. (This was Carrie's Intel project.)

But it's more complicated than that! Sometime you're not just expacting the simplest structure. Some verbs are much more likely to appear in a specific structure. For example:

> I looked at the lobster with-

Usually won't have you follow up with "my eyes", even if it's the simplest structure. This means your brain has to not only store *all* possible structures the word/structure can appear in, but which structures it's most *common* for this word/pattern to appear in.

#### Development

This can quickly get mind-numbingly complicated. Basically, the takeaway is that these sounds/words/patterns fit together logically, and it's up to the neural net to store these rules and fit the structures together on the fly. (The context around you can play a role as well. Parsing is a process of culling input from multiple constraints (syntax, semantics, context) and making the smartest guess about the upcoming words in a sentece based on what is molt likely. Crunching this much data, this quickly, is absolutley amazing, and still eludes AI for now. (although we're getting there)

I left out some details in this next section because sleepy, so be sure to ask Professor Nappa for the PDF.

This develops over time. 5 year olds show a strong preference towards verbs, even in actions, for example, as their language parsers aren't fully optimized yet. We're not sure why the parset takes so long to optimize, so in 2001, Snedeker, Thorpe and Trueswell performed an experiment that showed 5 year olds only showed sensitivity to *verb* bias. They concluded that this was likely due to verb bias being the easiest version to understand.
