/************************************************************************
*
*  Author:           Rykir Evans
*  Email:            rjevans0408@my.msutexas.edu
*  Label:            P04
*  Title:            Perms and Combs
*  Course:           CMPS 2433 Discrete Structures
*  Professor:        Catherine Stringfellow
*  Semester:         Fall 2024
*
*  Description:      This program reads in permutation or combination
*                    operations from an input file and subsequently
*                    performs the respective operation. This program
*                    makes use of 2 custom factorial functions, one
*                    being iterative, and the other being recursive.
*                    Additionally, the program makes use of
*                    cancellation techniques when N gets exceptionally
*                    large. 
*
*  Usage:            The `prog4mine.dat` may be manipulated to test
*                    custome values. The input must be in the form of
*                    `P X Y` where X is an integer >= 1, and where Y
*                    is an integer 0 <= Y <= X. The results will be
*                    output to a specified file which will output the
*                    heading of the program, restate the operation,
*                    and the result. The file will end with the number
*                    of test cases performed.
*
*  Files:             Evans_combo.cpp  (main)
*                     prog4.dat        (Sample input)
*                     prog4mine.dat    (Custom input)
*                     Evans_combo1.txt (Output on sample)
*                     Evans_combo2.txt (Output on mine)
*                     
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
void printHeading(ostream&, string);

/*
 * iterFact
 *
 * Description:
 *      Calculates factorial using an iterative method
 *
 * Params:
 *  
 *  int       - The number to calculate factorial of
 *
 * Returns:
 *  long long - The factorial result
 */
long long iterFact(int);

/*
 * recFact
 *
 * Description:
 *      Calculates factorial using an recursive method
 *
 * Params:
 *  
 *  int       - The number to calculate factorial of
 *
 * Returns:
 *  long long - The factorial result
 */
long long recFact(int);

/*
 * permutation
 *
 * Description:
 *      Calculates number of ways r objects can be
 *      selected from n objects where order matters
 *
 * Params:
 *  
 *  int       - The total number of objects (Universe)
 *  int       - The subset of objects which are selected
 *
 * Returns:
 *  long long - The permutation result
 */
long long permutation(int n, int r);

/*
 * combination
 *
 * Description:
 *      Calculates number of ways r objects can be 
 *      selected from n objects where order is unimportant
 *
 * Params:
 *  
 *  int       - The total number of objects (Universe)
 *  int       - The subset of objects which are selected
 *
 * Returns:
 *  long long - The combination result
 */
long long combination(int, int);

int main()
{
    ifstream infile;
    ofstream outfile;
    long long ans;
    int N, R, testCases = 0;
    char type;

    // Prompt user to open files
    openFiles(infile, outfile);

    // Display heading
    printHeading(outfile, "Program 4 - Perms & Combs");

    while(!infile.eof())
    {
        infile >> type >> N >> R;
        // No data validation as per assn.

        // Call appropriate operative function
        switch(type)
        {
            case 'P': ans = permutation(N, R); break;
            case 'C': ans = combination(N, R); break;
            default : ans = -1;
                      outfile << "Invalid operation:" << endl;
        }

        // Display problem and answer
        outfile << type << "(" << setw(2) << right << N << ", " << right 
                << setw(2) << R << ") " << "=" << setw(20) << ans << left
                << endl;

        // Increment testCases
        testCases++;
    }

    outfile << endl << "There were " << testCases << " test cases.";

    infile.close();
    outfile.close();

}

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
void printHeading(ostream& os, const string title)
{
    os  << "Rykir Evans" << endl
        << title << endl << endl;
        // Removed initial test cases for this program as per assn.
        //<< "There are " << cases << " test cases." << endl << endl;
}

// recFact Definition
long long recFact(int n)
{
    // Base case and handle 0
    if(n <= 1)
        return 1;
    // Recursive call
    else
        return n * recFact(n - 1);
}

// iterFact Definition
long long iterFact(int n)
{
    // Check for 0 
    if(n == 0)
        return 1;

    long long temp = n;

    // Multiply consecutive numbers
    for(int i = n - 1; i > 0; i--)
    {temp *= i;}

    return temp;
    
}

// permutation Definition
long long permutation(int n, int r)
{
    // Calculating perm using iterative factorial function
    // Early exit for n = r
    if(n == r)
        return iterFact(n);

    // Test for relatively small n
    if(n <= 10)
    // Formula of permutation
        return iterFact(n)/(iterFact(n - r));

    else 
    {
        // Cancellation technique for large n
        long long temp = n;
        for(int i = n - r + 1; i < n; i++)
        { temp *= i;}

        return temp;
    }
}

// combination Definition
long long combination(int n, int r)
{
    // Check for equality
    if(n == r)
        return n;
    // Calculating perm using recursive factorial function
    // Test for relatively small n
    if(n <= 10)
        return recFact(n)/(recFact(n - r) * recFact(r));

    // Cancellation method where r > (n - r)
    else if ((n-r) <= r)
    {
        long long temp = n;
        for(int i = r + 1; i < n; i++)
        {temp *= i;}
        return (temp)/(recFact(n - r));
    }

    // Cancellation method where r < (n - r)
    else 
    {
        long long temp = n;
        for(int i = n - r + 1; i < n; i++)
        {temp *= i;}
        return (temp)/(recFact(r));
    }
}