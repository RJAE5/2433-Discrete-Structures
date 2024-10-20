## Program 2 - Square Summation
### Rykir Evans
### Description:

This program reads from an input file to test how many total squares can be formed out of an NxN grid of squares, where N is from the input file. The program displays calculations from 3 different ways of calculating the problem, but these will be equal.

### Files

|   #   | File                                        | Description                                              |
| :---: | ------------------------------------------- | -------------------------------------------------------- |
|   1   | [main.cpp](./main.cpp)                      | Main driver of my project that calls helper functions    |
|   2   | [Feynman.dat](./Feynman.dat)                | Given input file containing test cases for N             |
|   3   | [my_input.dat](./my_input.dat)              | Custom input file containing varying cases for N         |
|   4   | [Feynman_output.dat](./output.dat)          | Formatted output file based on given input file          |
|   5   | [my_output.dat](./my_output.dat)            | Formatted output file based on custom input file         |

### Instructions

Run the program using `./main` and the program will prompt the user for file names, upon which, the program will use whatever is typed in. For the first prompt, the user should type `Feynman.dat`, and for the second prompt, the user should type `Feynman_output.dat` to see the results of the assigned test cases. If the user wishes to test custom variables, they should fill out `my_input.dat` or use prefilled numers. The responses to the prompt should be `my_input.dat`, and `my_output.dat` respectively.  
The user will then find the respective output file containing a table displaying N on the far left column. The following 3 columns display different ways to calculate the summation of squares, but they will be equal.
