/************************************************************************
*
*  Author:           Rykir Evans
*  Email:            rjevans0408@my.msutexas.edu
*  Label:            P03
*  Title:            Decryption
*  Course:           CMPS 2433 Discrete Structures
*  Professor:        Catherine Stringfellow
*  Semester:         Fall 2024
*
*  Description:      This program reads in from a specified input file
*                    which contains garbled text. It counts the frequency
*                    of each letter and assumes the one that appears the
*                    most is the letter `E`. The program mathematically
*                    shifts the ASCII values for that character to E and
*                    does the same for every character in the message.
*                    The result is displayed to the console and prompts
*                    the user to see if the result seems correct and
*                    proceeds to output the result to a file.
*
*  Usage:            The `myInput.dat` file may be manipulated with text
*                    that is encrypted specifically using Ceaser's 
*                    Encryption. Alternatively, you may use the 
*                    `encrypt.cpp` program to encrypt your own message and
*                    relay this to the `myInput.dat` file. Call the program
*                    using `./main` and enter the files as prompted.
*                    Respond to the console prompts and results will be
*                    stored in the specified output file.
*
*  Files:             main.cpp
*                     CipherText.dat
*                     CipherTextOutput.dat
*                     myInput.dat 
*                     myOutput.dat
*
*  Helper Files:      encrypt.cpp
*  (Not necessary)    encryptInfile.dat
*                     encryptOutfile.dat
*                     
************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/*
 * openFiles
 *
 * Description:
 *      Prompts the user for file names and proceeds
 *      to open those files.
 *
 * Params:
 *  ifstream& - The file reader object
 *  ofstream& - The file output object
 *
 * Returns:
 *  void      - Returns nothing, all information passed back by &
 */
void openFiles(ifstream&, ofstream&);

/*
 * printHeading
 *
 * Description:
 *      Prints the heading using a specified
 *      ostream
 *
 * Params:
 *  
 *  ostream&  - The output stream object
 *  string    - The title of the program
 *  int       - The number of test cases for heading
 *
 * Returns:
 *  void      - Returns nothing, all information passed back by &
 *              or output to ostream
 */
void printHeading(ostream&, string, int);

/*
 * freqCounter
 *
 * Description:
 *      Tallies every appearance of each letter
 *      within the message
 *
 * Params:
 *  
 *  string    - The encrypted message
 *  int array - The tally holder for each letter 1-26
 *
 * Returns:
 *  void      - Returns nothing, all information passed back by &
 *              or output to ostream
 */
void freqCounter(string, int f[27]);

/*
 * findHigh
 *
 * Description:
 *      Simple linear search to find the most frequently 
 *      occuring letter from the tally array
 *
 * Params:
 *  
 *  int array - The tally holder to be searched
 *
 * Returns:
 *  int       - The index (or letter) that occures the most
 */
int findHigh(int f[27]);

/*
 * shiftAmount
 *
 * Description:
 *      Mathematical operations performed on the ASCII
 *      value to obtain proper shift amount
 *
 * Params:
 *  
 *  int       - The number corresponding to the most common letter
 *
 * Returns:
 *  int       - The difference (or shift) needed to correct all letters
 */
int shiftAmount(int);

/*
 * decrypt
 *
 * Description:
 *      Shifts all letters within the encrypted
 *      message by the shift amount to obtain
 *      the correct message
 *
 * Params:
 *  
 *  string    - The original encrypted message
 *  int       - The shift amount
 *
 * Returns:
 *  int       - The index (or letter) that occures the most
 */
string decrypt(string, int);

int main()
{
    // Filestreams and variables
    ifstream infile;
    ofstream outfile;
    string message;
    char assumedE;
    char ans;
    int testCases;
    int count = 0;
    
    // File preperation
    openFiles(infile, outfile);
    infile >> testCases;

    // Data validation
    if(testCases < 1 || testCases > 10)
    {
        cout << "Invalid number of test cases, must be 1 - 10. "
             << "Please start over and enter a valid number of cases."
             << endl;
        outfile << "ERROR: Invalid number of test cases. Please try again.";
        infile.close();
        outfile.close();
        return 0;
    }
    
    // Headings for file and console
    printHeading(outfile, "Decryption - Program 3", testCases);
    printHeading(cout, "Decryption - Program 3", testCases);
    
    // Main repetition loop
    while(count < testCases)
    {
        // Array to store frequency of letters
         int frequency[27] = {0};

        // Get and display message
        getline(infile, message, '#');
        outfile << "Test Case: " << count + 1 << endl
                << "Encrypted Message:" << endl << message << endl << endl;
        
        // Find and assign most frequently used letter
        freqCounter(message, frequency);
        assumedE = findHigh(frequency) + 65;

        // Obtain decrypted message
        string decrypted = decrypt(message, shiftAmount(assumedE));
        
        // Print decrypted to outfile
        outfile << "Decrypted Message:" << endl
                << decrypted << endl;

        // Prompt user to verify if decrypted message is correct
        cout << "Test Case: " << count + 1 << endl;
        cout << decrypted << endl << endl;
        cout << "Is the above message readable? Y/N" << endl;
        cin >> ans;

        // Data validation
        if(ans != 'Y' && ans != 'N' && ans != 'y' && ans != 'n')
            while(ans != 'Y' && ans != 'N' && ans != 'y' && ans != 'n')
                {
                    cout << "Invalid answer, please try again..." << endl;
                    cin >> ans;
                }
        
        // Correctly decrypted messages logged as successful
        if(ans == 'Y' || ans == 'y')
        {
            cout << "Fantastic!" << endl << "Continuing..." << endl << endl;
            outfile << "Result: Successfully Decrypted!" << endl << endl;
        }

        // Incorrectly decrypted messages logged as unsuccessful
        else
        {
            cout << "The message does not use the letter `E` the most" << endl
                 << "Continuing..." << endl << endl;

            outfile << "Result: Unsuccessful." << endl;
        }

        count++;
    }// End while loop

    // Final console statement
    cout << "Finished all test cases. " << endl
         << "You may review the output file for results!" << endl;

    // Close files and end main
    infile.close();
    outfile.close();
    return 0;

}// End main

// openFiles Definition
void openFiles(ifstream& infile, ofstream& outfile)
{
    char inFileName[40];
    char outFileName[40];

    // Open input file
    cout << "Enter the input file name: ";
    cin >> inFileName;
    infile.open(inFileName); 
    
    // Open output file
    cout << "Enter the output file name: ";
    cin >> outFileName;
    outfile.open(outFileName);
}

// printHeading Definition
void printHeading(ostream& os, const string title, int cases)
{
    os  << "Rykir Evans" << endl
        << title << endl << endl
        << "There are " << cases << " test cases." << endl << endl;
}

// freqCounter Definition
void freqCounter(string m, int f[27])
{
    int letter;
    for(int i = 0; i < m.size(); i++)
    {
        // Data validation
        if(m[i] >= 'A' && m[i] <= 'Z')
        {
            // ASCII math to store in appropriate array index
            letter = m[i] - 'A' + 1;
            f[letter]++;
        }
    }

}

// findHigh Definition
int findHigh(int f[27])
{
    int letter = 1;
    
    // Linear search to find highest frequency letter
    for(int i = 2; i < 27; i++)
    {
        if(f[letter] < f[i])
        letter = i;
    }
     
    return letter;
}

// shiftAmount Definition
int shiftAmount(int assumedE)
{
    // Convert from ASCII to normal alphabet number
    assumedE -= 'A';

    // 26 letters + starting point of E
    // Subtract assumedE, and this will give the correct letter
    // Once %26 is performed
    return 26 + 5 - assumedE;
}

// decrypt Definition
string decrypt(string m, int shift)
{
    string decrypted = m;

        for(int i = 0; i < m.size(); i++)
        {
            // Conditional for letters
            if(m[i] >= 'A' && m[i] <= 'Z')
                {
                    // Convert from ASCII to normal alphabet numbers
                    // Shift forward and loop back using mod
                    char newChar = ((m[i] - 'A') + shift) % 26;

                    // Convert back to ASCII
                    decrypted[i] = newChar + 'A';
                }
            // Non-standard letters stay the same
            else
                decrypted[i] = m[i];
        }
        return decrypted;
}