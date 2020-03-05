# postfixCal
This is a simple calculator which takes a single line string of operands, operators, and functions as input and produces the result of the simplification as output. For example, (3-4)+8*(max(3, 4)), gives 31. 

The program is divided into four parts : tokenizer.cpp, lexer.cpp, infixToPostfix.cpp, postfix_eval.cpp.
The first two programs tokenizes the string into tokens of type - operators, operands, functions and parentheses. 
Then the tokenized string is converted to postfix from infix using the Shunting-Yard Algorithm. Lastly, the postfix string is evaluated to give the output. 

## Building
To build, use `make` and run the project by `./calc` (This is compiled with GCC 9.1.0)

## Example
`$./calc`

`->1+  2*8*max(5,7)`

`->113`

`->`
## To-be done:
1. Error handling.
2. User defined functions(maybe)
#### Thanks for reading!
