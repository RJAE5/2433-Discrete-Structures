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
|   6   | [encrypt.cpp](./encrypt.cpp)                   | Helper program to encrypt custom messages                |
|   7   | [encryptInfile.dat](./encryptInfile.dat)       | Input file for helper encryption program                 |
|   8   | [encryptOutfile.dat](./encryptOutfile.dat)     | Output file for helper encryption program                |

### Instructions

Run the program using `./main` and the program will prompt the user for file names, upon which, the program will use whatever is typed in. For the first prompt, the user should type `CipherText.dat`, and for the second prompt, the user should type `CipherTextOutput.dat` to see the results of the assigned test cases. If the user wishes to test custom message, they should fill out `myInput.dat` using messages that are specifically encrypted using Ceasar's Method, or use prefilled examples. Alternatively, you may use the `encrypt.cpp` helper program to encrypt your own message and relay this to the `myInput.dat` file.
The responses to the prompt should be `myInput.dat`, and `myOutput.dat` respectively.  

#### Using `encrypt.cpp`
The user must enter the message they want to encrypt in ALL CAPS and must end the message with a pound sign `#`.

Example: `ENCRYPT THIS MESSAGE#` 

Run the program using `./encrypt` and the program will prompt the user for file names, upon which, the program will use whatever is typed in. For the first prompt, the user should type `encryptInfile.dat`, and for the second prompt, the user should type `encryptOutfile.dat` or use custom files. The program will additionally prompt the user for the amount of messages they wish to encrypt. The user should enter a number 1-10 depending on how many messages they have to encrypt in the input file. Finally, the program will prompt the user for a shift number for  each message. The user should enter a number 1-25 and each character will be shifted that number of times. The encrypted message will be output to the specified file in the format that is required for `main.cpp`.