## Program 3 - Decryption
### Rykir Evans
### Description:

This program reads in from a specified input file which contains garbled text. It counts the frequency of each letter and assumes the one that appears the most is the letter `E`. The program mathematically shifts the ASCII values for that character to E (69) and does the same shift for every character in the message. The result is displayed to the console and prompts the user to see if the result seems correct and proceeds to output the result to a specified file.

### Files

|   #   | File                                           | Description                                              |
| :---: | ---------------------------------------------- | -------------------------------------------------------- |
|   1   | [main.cpp](./main.cpp)                         | Main driver of my project that calls helper functions    |
|   2   | [CipherText.dat](./CipherText.dat)             | Given input file containing assigned test cases          |
|   3   | [CipherTextOutput.dat](./CipherTextOutput.dat) | Formatted output file based on assigment input file      |
|   4   | [myInput.dat](./myInput.dat)                   | Custom input file containing varying examples            |
|   5   | [myOutput.dat](./myOutput.dat)                 | Formatted output file based on custom input file         |

### Instructions

Run the program using `./main` and the program will prompt the user for file names, upon which, the program will use whatever is typed in. For the first prompt, the user should type `CipherText.dat`, and for the second prompt, the user should type `CipherTextOutput.dat` to see the results of the assigned test cases. If the user wishes to test custom message, they should fill out `myInput.dat` using messages that are specifically encrypted using Ceasar's Method, or use prefilled examples. Alternatively, you may use the [encrypt.cpp](./helper_encryption_program/) helper program to encrypt your own message and relay this to the `myInput.dat` file.
The responses to the console prompts should be `myInput.dat`, and `myOutput.dat` respectively.  

#### Using [encrypt.cpp](./helper_encryption_program/)
See [encrypt.cpp](./helper_encryption_program/) for detailed instructions on use.