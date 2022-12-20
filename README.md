# Csq-Version3
This is one more version of Csq programming language which's syntax looks much similar to Python and much faster than Csq Version-2.

# Requirement
> You should have g++ compiler

## How does it works in backend?
It's processes are similar to the in the programming language Nim but here what it does it that a Intermediate code converter converts .csq to .csqm and later .csqm is converted to .cpp and it uses a prebuilt C++ compiler such as in this it uses clang++ to produce output.
## What is new?
<li>Speed is made faster than Csq version-2.</li>
<li>Functions can be used in main file.</li>
<li>Syntax for for loop is enhanced.</li>
<li>Speed of imported module is faster.</li>
<li>Code of CsqV2 couldn't be used in this.</li>
<li>You could add new tokens to it by changing base/token.h.</li>

## How to build Csq?
<li> git clone https://github.com/CsqLang/Csq3 </li>
<li> cd Csq-Version3 && bash build.sh</li>

## Some examples:

<h3>Hello World</h3>

> print("Hello World")

<h3>Creating Variables</h3>

> var i = 48 <br>
  //int i = 48
  //But if you want to define a str so don't write like var v = "hello" because in this case it's considered as const char* use var v = str("hello")
  
<h3>if else if and else</h3>
if condition so
  .....
ends
else if condition so
  .....
ends
else go
  .....
ends
<h3>For loop</h3>

> for var i : range(11)<br>
  &nbsp;print(i,",") <br>
  ends
  
 <h3>Functions</h3>

> def fizz()<br>
    &nbsp;return str("BUZZ")<br>
  fizz ends<br>


 <h3>Functions with arguments</h3>

> def fizz(str name)<br>
    &nbsp;return name + " BUZZ"<br>
  fizz ends<br>
  fizz("Aniket")<br>
  
  
## New keywords::
> ["priv","pub","ends","meth"]
## To comment 
> to comment you could either use # or //
## What's inside base directory?
In base directory all necessary header are present such as for code analysis, strings, arrays ...
## How to change add or remove operators:
Go to base/token.h and there you will see a dictionary in which operators with their meaning in C++ are there. After changes compile csq.cpp and mcsq.cpp so that the changes can be applied.

## How it will provide memory safety if garbage collector isn't there?
Well to provide memory safety there is one class which applies the concept of Smart Pointers using this it will free the memory by it self.
