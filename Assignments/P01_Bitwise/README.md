## Program 1 - Bitwise
### Rykir Evans
### Description:

This program reads in a list of integers and does bitwise manipulation to achieve the index of the highest set bit within any integer. It proceeds to modify the original number by setting the next highest bit to a 1 using logical OR and displays the original integer, the index of it's highest bit, and the modified integer to an output file. 

### Files

|   #   | File                                        | Description                                              |
| :---: | ------------------------------------------- | -------------------------------------------------------- |
|   1   | [main.cpp](./main.cpp)                      | Main driver of my project that calls helper functions    |
|   2   | [HighBits.dat](./HighBits.dat)              | Input file containing integers                           |
|   3   | [Output.dat](./Output.dat)                  | Formatted output file based on input file                |

### Instructions

Fill out `HighBits.dat` or use prefilled numbers. Run the program using `./main` and the program will prompt the user for file names, upon which it will use whatever is typed in. For the first prompt, the user should type `HighBits.dat`, and for the second prompt, the user should type `Output.dat`.
The user will then find the output file containing the original integer, the index of it's highest set bit, and a hypothetical number if the next highest bit were set to 1.
