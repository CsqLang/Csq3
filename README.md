# Csq-Version3
This is one more version of Csq programming language which's syntax looks much similar to Python and much faster than Csq Version-2.

## How does it works in backend?
It's processes are similar to the in the programming language Nim but here what it does it that a Intermediate code converter converts .csq to .csqm and later .csqm is converted to .cpp and it uses a prebuilt C++ compiler such as in this it uses clang++ to produce output.
## What is new?
<li>Speed is made faster than Csq version-2.</li>
<li>Functions can be used in main file.</li>
<li>Syntax for for loop is enhanced.</li>
<li>Speed of imported module is faster.</li>
<li>Code of CsqV2 couldn't be used in this.</li>
<li>You could add new tokens to it by changine base/token.h.</li>

## Some examples:

<h3>Hello World</h3>

> print("Hello World")

<h3>For loop</h3>

> for var i : range(11) so <br>
  print(i,",") <br>
  ends
  
 <h3>Functions</h3>

> def fizz(){<br>
    return str("BUZZ")<br>
  }<br>


 <h3>Functions with arguments</h3>

> def fizz(str name){<br>
    return name + " BUZZ"<br>
  }<br>
  fizz("Aniket")<br>

## New keywords::
> ["go","so","ends","meth"]
## To comment 
> to comment you could either use # or //
## What's inside base directory?
In base directory all necessary header are present such as for code analysis, strings, arrays ...
## How to change add or remove operators:
Go to base/token.h and there you will see a dictionary in which operators with their meaning in C++ are there. After changes compile csq.cpp and mcsq.cpp so that the changes can be applied.
