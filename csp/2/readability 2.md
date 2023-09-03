# [Readability](#readability)

After watching the entire [Chapter 2 lecture]({{ "/csp/2" | relative_url }}) and the practice problems, implement a program that computes the approximate grade level needed to comprehend some text, per the below.

```
$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 2
```
{:.no_toc}

* TOC
{:toc}
## [Reading Levels](#reading-levels)

According to [Scholastic](https://www.scholastic.com/teachers/teaching-tools/collections/guided-reading-book-lists-for-every-level.html), E.B. White’s “Charlotte’s Web” is between a second and fourth grade reading level, and Lois Lowry’s “The Giver” is between an eighth grade reading level and a twelfth grade reading level. What does it mean, though, for a book to be at a “fourth grade reading level”?

Well, in many cases, a human expert might read a book and make a decision on the grade for which they think the book is most appropriate. But you could also imagine an algorithm attempting to figure out what the reading level of a text is.

So what sorts of traits are characteristic of higher reading levels? Well, longer words probably correlate with higher reading levels. Likewise, longer sentences probably correlate with higher reading levels, too. A number of “readability tests” have been developed over the years, to give a formulaic process for computing the reading level of a text.

One such readability test is the Automated Readability Index (ARI). The ARI of a text is designed to output what (U.S.) grade level is needed to understand the text. The formula is:

```
score = 4.71 * C + 0.5 * S - 21.43
```

Here, `C` is the average number of alphanumeric characters per word, and `S` is the average number of words per sentence. We can then round up to the nearest integer if necessary and subtract 1 to get the grade level, with 0 or below being Kindergarten and 13 or above being College student.

Let’s write a program called `readability` that takes a text and determines its reading level. For example, if user types in a line from Dr. Seuss:

```
$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 2
```

The text the user inputted has 65 characters, 4 sentences, and 14 words. 65 characters per 14 words is an average of about 4.64 characters per word. And 14 words in 4 sentences is an average of 3.5 words per sentence. Plugged into the ARI formula, rounded up, and decremented by 1, we get an answer of 2. So, according to the Automated Reliability Index, this passage is at a second grade reading level.

Let’s try another one:

```
$ ./readability
Text: Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.
Grade 3
```

This text has 214 characters, 4 sentences, and 56 words. That comes out to about 3.82 characters per word, and 14 words per sentence. Plugged into the ARI formula, we get a third grade reading level.

As the average number of characters/word and words/sentence increases, the ARI gives the text a higher reading level. If you were to take this paragraph, for instance, the formula would give the text an eleventh grade reading level.

```
$ ./readability
As the average number of characters/word and words/sentence increases, the ARI gives the text a higher reading level. If you were to take this paragraph, for instance, the formula would give the text an eleventh grade reading level.
Grade 11
```

## [Specification](#specification)

Design and implement a program, `readability`, that computes the Automated Readability Index of the text.

-   Implement your program in a file called `readability.c` in a `~/pset2/readability` directory.
-   Your program must prompt the user for a `string` of text (using `get_string`).
-   Your program should count the number of alphanumeric characters, words, and sentences in the text. You may assume that an alphanumeric character is any lowercase character from `a` to `z` or any uppercase character from `A` to `Z` or number `0` to `9`, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
-   Your program should print as output `"Grade X"` where `X` is the grade level computed by the ARI formula, rounded up to the nearest integer if necessary, and decremented by 1.
-   If the resulting index number is 13 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output `"College Student"` instead of giving the exact index number. If the index number is less than 1, your program should output `"Kindergarten"`.

### [Getting User Input](#getting-user-input)

Let’s first write some C code that just gets some text input from the user, and prints it back out. Specifically, write code in a new file called `readability.c` such that when the user runs the program, they are prompted with `"Text: "` to enter some text.

The behavior of the resulting program should be like the below.

```
$ ./readability
Text: In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.
In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.
```

### [Alphanumerals](#letters)

Now that you’ve collected input from the user, let’s begin to analyze that input by first counting the number of alphanumeric characters that show up in the text. Modify `readability.c` so that, instead of printing out the literal text itself, it instead prints out a count of the number of alphanumeric characters in the text.

The behavior of the resulting program should be like the below.

```
$ ./readability
Text: Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, "and what is the use of a book," thought Alice "without pictures or conversation?"
235 character(s)
```

Letters can be any uppercase or lowercase alphabetic characters or digits, but shouldn’t include any punctuation or other symbols.

You can reference [https://man.cs50.io/](https://man.cs50.io/) for standard library functions that may help you here! You may also find that writing a separate function, like `count_letters`, may be useful to keep your code organized.

### [Words](#words)

The Automated Readability Index cares not only about the number of characters, but also the number of words. For the purpose of this problem, we’ll consider any sequence of characters separated by a space to be a word (so a hyphenated word like `"sister-in-law"` should be considered one word, not three).

Modify `readability.c` so that, in addition to printing out the number of alphanumeric characters in the text, also prints out the number of words in the text.

You may assume that a sentence will not start or end with a space, and you may assume that a sentence will not have multiple spaces in a row.

The behavior of the resulting program should be like the below.

```
$ ./readability
Text: It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.
250 character(s)
55 word(s)
```

### [Sentences](#sentences)

The last piece of information that the ARI formula cares about, in addition to the number of characters and words, is the number of sentences. Determining the number of sentences can be surprisingly trickly. You might first imagine that a sentence is just any sequence of characters that ends with a period, but of course sentences could end with an exclamation point or a question mark as well. But of course, not all periods necessarily mean the sentence is over. For instance, consider the sentence below.

```
Mr. and Mrs. Dursley, of number four Privet Drive, were proud to say that they were perfectly normal, thank you very much.
```

This is just a single sentence, but there are three periods! For this problem, we’ll ask you to ignore that subtlety: __you should consider any sequence of characters that ends with a `.` or a `!` or a `?` to be a sentence__ (so for the above “sentence”, you may count that as three sentences). In practice, sentence boundary detection needs to be a little more intelligent to handle these cases, but we’ll not worry about that for now.

Modify `readability.c` so that it also now prints out the number of sentences in the text.

The behavior of the resulting program should be like the below.

```
$ ./readability
Text: When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.
295 character(s)
70 word(s)
3 sentence(s)
```

### [Putting it All Together](#putting-it-all-together)

Now it’s time to put all the pieces together! Recall that the Coleman-Liau index is computed using the formula:

```
score = 4.71 * C + 0.5 * S - 21.43
```

Here, `C` is the average number of alphanumeric characters per word, and `S` is the average number of words per sentence. We can then round up to the nearest integer if necessary and subtract 1 to get the grade level, with 0 or below being Kindergarten and 13 or above being College student.

Modify `readability.c` so that instead of outputting the number of letters, words, and sentences, it instead outputs the grade level as given by the Coleman-Liau index (e.g. `"Grade 2"` or `"Grade 8"`). Be sure to round the resulting index number up to the nearest whole number and subtract 1! (So, `11.1` becomes `11` and `9` becomes `8`).

If the resulting index number is 13 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output `"College Student"` instead of giving the exact index number. If the index number is less than 1, your program should output `"Kindergarten"`.

Hints

-   Recall that `math.h` declares a function called `round` that might be useful here.
    
-   Recall that, when dividing values of type `int` in C, the result will also be an `int`, with any remainder (i.e., digits after the decimal point) discarded. Put another way, the result will be “truncated.” You might want to cast your one or more values to `float` before performing division when calculating `L` and `S`!
    

## [Walkthrough](#walkthrough)

<iframe allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen="" class="border embed-responsive-item" data-video="" src="https://www.youtube.com/embed/nif3h2ggrOU?modestbranding=0&amp;rel=0&amp;showinfo=0" scrolling="no" id="iFrameResizer0" style="overflow: hidden;"></iframe>

__Note__ that while the walkthrough illustrates that words may be separated by more than one space, you may assume, per the specifications above, that no sentences will contain more than one space in a row. The walkthrough also uses a different formula which change the specifications slightly, but the advice should still be relevant to this task.

## [How to Test Your Code](#how-to-test-your-code)

Try running your program on the following texts.

-   `One fish. Two fish. Red fish. Blue fish.` (Kindergarten)
-   `Would you like them here or there? I would not like them here or there. I would not like them anywhere.` (Kindergarten)
-   `Congratulations! Today is your day. You're off to Great Places! You're off and away!` (Grade 2)
-   `Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.` (Grade 3)
-	`Everything about me is a contradiction, and so is everything about everybody else. We are made out of oppositions; we live between two poles. There's a philistine and an aesthete in all of us, and a murderer and a saint. You don't reconcile the poles. You just recognize them.` (Grade 4)
-	`Franklin could count by twos and tie his shoes. He could name the months of the year and all the seasons. He could read the thermometer, and he checked the barometer every day. Franklin worried about the weather because he was afraid of storms.` (Grade 5)
-   `There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy.` (Grade 7)
-   `In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.` (Grade 9)
-   `When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.` (Grade 10)
-   `The rule of rhythm in prose is not so intricate. Here, too, we write in groups, or phrases, as I prefer to call them, for the prose phrase is greatly longer and is much more nonchalantly uttered than the group in verse; so that not only is there a greater interval of continuous sound between the pauses, but, for that very reason, word is linked more readily to word by a more summary enunciation. Still, the phrase is the strict analogue of the group, and successive phrases, like successive groups, must differ openly in length and rhythm. Prose must be rhythmical, and it may be as much so as you will; but it must not be metrical. It may be anything, but it must not be verse.` (Grade 11)
-   `A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains.` (College Student)

Execute the below to evaluate the correctness of your code using `check50`. But be sure to compile and test it yourself as well!

```
check50 cs-acs/problems/main/readability
```

Execute the below to evaluate the style of your code using `style50`.

```
style50 readability.c
```

## [How to Submit](#how-to-submit)

Execute the below, logging in with your GitHub username and password when prompted. For security, you’ll see asterisks (`*`) instead of the actual characters in your password.

```
submit50 cs-acs/problems/main/readability
```