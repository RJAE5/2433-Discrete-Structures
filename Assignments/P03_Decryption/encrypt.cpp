/************************************************************************
*
*  Author:         Rykir Evans
*  Label:          P03
*  File:           encrypt.cpp
*
*  Description:   This is a helper program for `Program 3 - Decryption`.
*                 It is not necessary for `main.cpp` to run. It is used
*                 when the user wishes to encrypt their own message using
*                 Ceasar's method. It reads in from a specified input file
*                 and prompts the user for how many messages they wish to
*                 encrypt, and the shift number they wish to use (1-25).
*                 Results are displayed to a specified output file
*
*  Usage:         The user must enter the message they want to encrypt
*                 in ALL CAPS and must end the message with a pound sign
*                 Ex. `ENCRYPT THIS MESSAGE#`
*                 Run the program using `./encrypt` and the program will
*                 prompt the user for file names, upon which, the program
*                 will use whatever is typed in. For the first prompt, the
*                 user should type `encryptInfile.dat`, and for the second
*                 prompt, the user should type `encryptOutfile.dat` or use
*                 custom files. The program will additionally prompt the 
*                 user for the amount of messages they wish to encryp. The
*                 user should enter a number 1-10 depending on how many
*                 messages they have to encrypt in the input file. Finally,
*                 the program will prompt the user for a shift number for 
*                 each message. The user should enter a number 1-25 and
*                 each character will be shifted that number of times.  
*
*                     
************************************************************************/
#include <iostream>
#include <fstream>
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

int main()
{
    // File streams and variables
    ifstream infile;
    ofstream outfile;
    string oMessage, eMessage;
    int shift, testCases, count = 0;
    
    openFiles(infile, outfile);

    // Console displayed guidelines
    cout << "Please ensure the message you wish to encrypt is already "
         << "within the input file, additionally, please follow these "
         << "guidelines when typing your message: " << endl
         << "Message is typed in ALL CAPS" << endl
         << "Message ends with `#`" << endl << endl;
    
    // Prompt for messages
    cout << "Please indicate how many messages you would like to encrypt "
         << "(1 - 10): ";
    cin >> testCases;

    // Data validation
    if(testCases < 1 || testCases > 10)
    {
        while(testCases < 1 || testCases > 10)
        cout << "Invalid number of test cases, "
             << "please enter a number 1 - 10" << endl;
        cin >> testCases;
    }

    outfile << testCases << endl;

    // Main loop
    while(count < testCases)
    {
        // Prompt for shift
        cout << "Please indicate how many places you would like to shift "
             << "(1 - 25) for message " << count + 1 << ": ";
        cin >> shift;

        // Data validation
        if(shift < 1 || shift > 25)
        {
            while(shift < 1 || shift > 25)
            {
                cout << "Invalid shift, please enter a number 1 - 25: ";
                cin >> shift;
            }
        }

        // Read original message from file
        getline(infile, oMessage, '#');

        // Assign encrypted message
        eMessage = oMessage;

        for(int i = 0; i < oMessage.size(); i++)
        {
            // Encrypt each letter
            if(oMessage[i] >= 'A' && oMessage[i] <= 'Z')
            {
                oMessage[i] -= 'A';
                eMessage[i] = (oMessage[i] + shift) % 26;
                eMessage[i] += 'A';
            }
        }

        // Display message to outfile
        outfile << eMessage << '#';
        count++;
    }

    // Final statements and end main
    cout << "All messages are encrypted" << endl;
    infile.close();
    outfile.close();
    return 0;

}

// openFiles Definition
void openFiles(ifstream& infile, ofstream& outfile)
{
    char inFileName[40];
    char outFileName[40];

    //open input file
    cout << "Enter the input file name: ";
    cin >> inFileName;
    infile.open(inFileName); 
    
    //open output file
    cout << "Enter the output file name: ";
    cin >> outFileName;
    outfile.open(outFileName);
}