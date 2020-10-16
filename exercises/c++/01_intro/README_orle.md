# Exercises - session 01

## Understanding compiler messages
- Take a simple program (e.g., the hello world one) and put one at a time the following errors. Compile it and try to understand the error messages. If you have different compilers compare the messages from the two compilers.
  - do not put the `main` function
  - typos in function name (e.g., `c0ut`)
  - typos in variable name
  - forget to put `;`
  - forget to `#include <iostream>`
  - declare a variable with illegal name like `int double {0};`

*For this exercise see the outputs of each typos in the file: compilermessages.txt*

## uniq
- Write a simple version of the Unix program `uniq -c`, which, when fed with a text, outputs the same text with **consecutive** identical lines collapsed into one prepended with the number of repetitions. 

You can scan the stdin as follows
```
std::string line;
while(std::getline(std::cin,line))
{...}
```
or
```
for(std::string line; std::getline(std::cin,line);)
{...}
```
What do you think it is better? Why?

*I have used the while loop because in this case we know the condition for the loop stop, this condition is specific: when the string ends. I think the for loop works well and in the same way, i.e. there is no relevant differences between for and while loop in this case*. 

Remember that if you type directly from stdin, you should press `Ctr+D` to close the stdin without interrupting the program. Moreover, you can redirect the content of a text to stdin trough the `<` operator
```
./a.out <a_file
```

You can compare strings with the `==` operator
```
std::string s1;
std::string s2;
...
if(s1 == s2)
if(s1 != s2)
```

`std::string` and `std::getline` are defined in the header `<string>`, so, remember to include it!

## Getters
- write a function `get_int` that reads from stdin until a valid number is fed
- write a function `get_double` that reads from stdin until a valid number is fed.

*Hints*: 
You can keep reading from stdin using one of two statements
```
while(std::cin >> i)
```
or
```
while(!(std::cin >> i))
```
what is the difference?

*The option while(!(std::cin >> i)) will keep asking you for the correct input, once the correct input (integer or double) is introduced it will stop. The option while(std::cin >> i) will stop only when I give it the incorrect input (in this case a string or character), if I give it the correct one it will never stop. 

After that a wrong input has been parsed, you have to clear the error flag from `std::cin` calling
```
std::cin.clear();
```
and ignore what just read
```
std::cin.ignore();
```

## Units of measure

- Write a code that reads a number with its proper unit of measure, and prints back that number according to the SI units, e.g.

```
1 inch
0.0254 m
```

*I wrote a code that receives as an input the temperature in Celsius (C) or in Fahrenheit (F) and returns the temperature in Kelvin.*

## **Optional**: Text formatter
- Write a simple text formatter that breaks the lines longer than a given number of characters. This formatter does not break words and leaves unmodified the lines shorter than the given threshold.
