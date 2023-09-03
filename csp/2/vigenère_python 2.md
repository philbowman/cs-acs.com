# [Vigenere](#specification)
## [Background](https://docs.cs50.net/2018/x/psets/2/vigenere/vigenere.html#background#background)

Vigenère’s cipher improves upon Caesar’s cipher by encrypting messages using a sequence of keys (or, put another way, a keyword). In other words, if _p_ is some plaintext and _k_ is a keyword (i.e., an alphbetical string, whereby A represents 0, B represents 1, C represents 2, …, and Z represents 25), then each letter, _c<sub>i</sub>_, in the ciphertext, _c_, is computed as:

$$
c_i = (p_i + k_j) \bmod 26
$$$$
c_i = (p_i + k_j) \bmod 26
$$

Note this cipher’s use of _k<sub>j</sub>_ as opposed to just _k_. And if _k_ is shorter than _p_, then the letters in _k_ must be reused cyclically as many times as it takes to encrypt _p_.

In other words, if Vigenère himself wanted to say HELLO to someone confidentially, using a keyword of, say, ABC, he would encrypt the H with a key of 0 (i.e., A), the E with a key of 1 (i.e., B), and the first L with a key of 2 (i.e., C), at which point he’d be out of letters in the keyword, and so he’d reuse (part of) it to encrypt the second L with a key of 0 (i.e., A) again, and the O with a key of 1 (i.e., B) again. And so he’d write HELLO as HFNLP.

<table class="tableblock frame-all grid-all stretch"><caption class="title">Table 1. Encrypting HELLO with a keyword of ABC (reused cyclically as ABCAB) yields HFNLP.</caption> <colgroup><col style="width: 16.6666%;"> <col style="width: 16.6666%;"> <col style="width: 16.6666%;"> <col style="width: 16.6666%;"> <col style="width: 16.6666%;"> <col style="width: 16.667%;"></colgroup><tbody><tr><td class="tableblock halign-left valign-top"><p class="tableblock"><strong>plaintext</strong></p></td><td class="tableblock halign-left valign-top"><p class="tableblock">H</p></td><td class="tableblock halign-left valign-top"><p class="tableblock">E</p></td><td class="tableblock halign-left valign-top"><p class="tableblock">L</p></td><td class="tableblock halign-left valign-top"><p class="tableblock">L</p></td><td class="tableblock halign-left valign-top"><p class="tableblock">O</p></td></tr><tr><td class="tableblock halign-left valign-middle" rowspan="2"><p class="tableblock"><strong>+ key</strong></p></td><td class="tableblock halign-left valign-top"><p class="tableblock">A</p></td><td class="tableblock halign-left valign-top"><p class="tableblock">B</p></td><td class="tableblock halign-left valign-top"><p class="tableblock">C</p></td><td class="tableblock halign-left valign-top"><p class="tableblock">A</p></td><td class="tableblock halign-left valign-top"><p class="tableblock">B</p></td></tr><tr><td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td><td class="tableblock halign-left valign-top"><p class="tableblock">1</p></td><td class="tableblock halign-left valign-top"><p class="tableblock">2</p></td><td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td><td class="tableblock halign-left valign-top"><p class="tableblock">1</p></td></tr><tr><td class="tableblock halign-left valign-top"><p class="tableblock"><strong>= ciphertext</strong></p></td><td class="tableblock halign-left valign-top"><p class="tableblock">H</p></td><td class="tableblock halign-left valign-top"><p class="tableblock">F</p></td><td class="tableblock halign-left valign-top"><p class="tableblock">N</p></td><td class="tableblock halign-left valign-top"><p class="tableblock">L</p></td><td class="tableblock halign-left valign-top"><p class="tableblock">P</p></td></tr></tbody></table>

## Specification

Design and implement a program that encrypts messages using Vigenère’s cipher.

-   Implement your program in a file called `vigenere.py`.
    
-   Your program must accept a single command-line argument: a keyword, _k_, composed entirely of alphabetical characters.
    
-   If your program is executed without any command-line arguments, with more than one command-line argument, or with one command-line argument that contains any non-alphabetical character, your program should print an error (of your choice) and [exit](https://docs.python.org/3/library/sys.html#sys.exit) immediately with a status code of 1.
    
-   Otherwise, your program must proceed to prompt the user for a string of plaintext, _p_, (as by a prompt for `plaintext:`) which it must then encrypt according to Vigenère’s cipher with _k_, ultimately printing the result (prepended with `ciphertext:` and ending with a newline) and exiting.
    
-   With respect to the characters in _k_, you must treat `A` and `a` as 0, `B` and `b` as 1, … , and `Z` and `z` as 25.
    
-   Your program must only apply Vigenère’s cipher to a character in _p_ if that character is a letter. All other characters (numbers, symbols, spaces, punctuation marks, etc.) must be outputted unchanged. Moreover, if your code is about to apply the _j<sup>th</sup>_ character of _k_ to the _i<sup>th</sup>_ character of _p_, but the latter proves to be a non-alphabetical character, you must wait to apply that _j<sup>th</sup>_ character of _k_ to the next alphabetical character in _p_; you must not yet advance to the next character in _k_.
    
-   Your program must preserve the case of each letter in _p_.
    

## Walkthrough

<iframe src="https://www.youtube.com/embed/n4gcWaHKhoU?rel=0" frameborder="0" allowfullscreen="" class="embed-responsive-item"></iframe>

## Usage

Your program should behave per the examples below. Assume that the underlined text is what some user has typed.

```
$ python vigenere.py 13
Usage: python vigenere.py k
```

```
$ python vigenere.py
Usage: python vigenere.py k
```

```
$ python vigenere.py bacon and eggs
Usage: python vigenere.py k
```

```
$ python vigenere.py bacon
plaintext: Meet me at the park at eleven am
ciphertext: Negh zf av huf pcfx bt gzrwep oz
```

## Testing

To help you test `vigenere`, we’ve written a program called `devigenere` for you that also takes one and only one command-line argument (a keyword) but whose job is to take ciphertext as input and produce plaintext as output. To use our program, execute

```
~cs50/2019/ap/chapter6/devigenere k
```

at your prompt, where `k` is some keyword. Presumably you’ll want to paste your program’s output as input to our program; be sure, of course, to use the same key. Note that you do not need to implement `devigenere` yourself, only `vigenere`.

### Correctness

```
check50 cs50/problems/2019/ap/sentimental/vigenere
```

### Style

```
style50 vigenere.py
```

## Staff’s Solution

If you’d like to play with the staff’s own implementation of `vigenere`, you may execute the below.

```
~cs50/2019/ap/chapter6/vigenere
```

## How to Submit
    
```
submit50 cs50/problems/2019/ap/sentimental/vigenere
```

## Hints

Not sure where to begin? As luck would have it, this program’s pretty similar to `caesar`! Only this time, you need to decide which character in _k_ to use as you iterate from character to character in _p_.