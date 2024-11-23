## Program 2 - Square Summation
### Rykir Evans
### Description:

This program reads in permutation or combination operations from an input file and subsequently performs the respective operation. This program makes use of 2 custom factorial functions, one being iterative, and the other being recursive. Additionally, the program makes use of cancellation techniques when N gets exceptionally large. 

### Files

|   #   | File                                        | Description                                              |
| :---: | ------------------------------------------- | -------------------------------------------------------- |
|   1   | [Evans_combo.cpp](./Evans_combo.cpp)        | Main driver of my project that calls helper functions    |
|   2   | [prog4.dat](./prog4.dat)                    | Given input file containing perms and combs              |
|   3   | [prog4mine.dat](./prog4mine.dat)            | Custom input file containing varying cases               |
|   4   | [Evans_combo1.txt](./Evans_combo1.txt)      | Formatted output file based on given input file          |
|   5   | [Evans_combo2.txt](./Evans_combo2.txt)      | Formatted output file based on custom input file         |

### Instructions

Run the program using `./main` and the program will prompt the user for file names, upon which, the program will use whatever is typed in. For the first prompt, the user should type `prog4.dat`, and for the second prompt, the user should type `Evans_combo1.dat` to see the results of the assigned test cases. If the user wishes to test custom variables, they should fill out `prog4mine.dat` or use prefilled numbers. The responses to the prompt should be `prog4mine.dat`, and `Evans_combo2.txt` respectively.  
The user will then find the respective output file containing a list displaying the heading for the program, followed by each operation from the input file restated attached with the answer. The output file will end with the number of test cases.
