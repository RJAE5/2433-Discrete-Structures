## Program 3 - Decryption (Helper Encryption Program)
### Rykir Evans
### Description:

This is a helper program for `Program 3 - Decryption`. It is not necessary for `main.cpp` to run. It is used when the user wishes to encrypt their own message using Ceasar's method. It reads in from a specified input file and prompts the user for how many messages they wish to encrypt, and the shift number they wish to use (1-25). Results are displayed to a specified output file

|   #   | File                                           | Description                                              |
| :---: | ---------------------------------------------- | -------------------------------------------------------- |
|   1   | [encrypt.cpp](./encrypt.cpp)                   | Helper program to encrypt custom messages                |
|   2   | [encryptInfile.dat](./encryptInfile.dat)       | Input file for helper encryption program                 |
|   3   | [encryptOutfile.dat](./encryptOutfile.dat)     | Output file for helper encryption program                |


### Instructions
The user must enter the message they want to encrypt in ALL CAPS and must end the message with a pound sign `#`.

Example: `ENCRYPT THIS MESSAGE#` 

Run the program using `./encrypt` and the program will prompt the user for file names, upon which, the program will use whatever is typed in. For the first prompt, the user should type `encryptInfile.dat`, and for the second prompt, the user should type `encryptOutfile.dat` or use custom files. The program will additionally prompt the user for the amount of messages they wish to encrypt. The user should enter a number 1-10 depending on how many messages they have to encrypt in the input file. Finally, the program will prompt the user for a shift number for  each message. The user should enter a number 1-25 and each character will be shifted that number of times. The encrypted message will be output to the specified file in the format that is required for `main.cpp`.