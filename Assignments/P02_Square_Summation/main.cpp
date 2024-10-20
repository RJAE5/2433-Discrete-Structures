/************************************************************************
*
*  Author:           Rykir Evans
*  Email:            rjevans0408@my.msutexas.edu
*  Label:            P02
*  Title:            Square Summation
*  Course:           CMPS 2433 Discrete Structures
*  Professor:        Catherine Stringfellow
*  Semester:         Fall 2024
*
*  Description:      This program reads from an input file to test
*                    how many total squares can be formed out of an NxN
*                    grid of squares, where N is from the input file.
*                    The program displays calculations from 3 different
*                    ways of calculating the problem, but these are equal.
*
*  Usage:            You may edit the list of  N input values to determine
*                    the number of total squares formed from an NxN grid.
*
*  Files:             main.cpp
*                     Feynman.dat
*                     my_input.dat
*                     Feynamn_output.dat
*                     my_output.dat
************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

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
 * loopSum
 *
 * Description:
 *      Calculates the sum of squares using a for loop
 *
 * Params:
 *  int       - The base of the square to be summed
 *
 * Returns:
 *  int       - Returns the total number of squares possible
 */
int loopSum(int);

/*
 * recSum
 *
 * Description:
 *      Calculates the sum of squares using recursion
 *
 * Params:
 *  int       - The base of the square to be summed
 *
 * Returns:
 *  int       - Returns the total number of squares possible
 */
int recSum(int);

/*
 * closed
 *
 * Description:
 *      Calculates the sum of squares using a closed form solution
 *
 * Params:
 *  int       - The base of the square to be summed
 *
 * Returns:
 *  int       - Returns the total number of squares possible
 */
int closed(int);

/*
 * closeFiles
 *
 * Description:
 *      Closes files opened at the beginning of the program
 *
 * Params:
 *  ifstream& - The file reader object
 *  ofstream& - The file output object
 *
 * Returns:
 *  void      - Returns nothing, all information passed back by &
 */
void closeFiles(ifstream&, ofstream&);

int main()
{
    // Filestreams and variables
    ifstream infile;
    ofstream outfile;
    int testCases, N;

    // Prompt user to open files
    openFiles(infile, outfile);

    // Read test cases, print out heading
    infile >> testCases;

    outfile << "Rykir Evans" << endl
            << "Square Summation Program 2" << endl << endl
            << "There are " << testCases << " test cases." << endl << endl;

    // Print out table headings
    outfile << "N" << setw(17) << "IterativeSum" << setw(17) 
            << "RecursiveSum" << setw(12) << "Closed" << endl 
            << setfill('-') << setw(50) << " " << endl << setfill(' ')
            << right;

    // Print loop to run through cases
    while(infile >> N)
    {
        // Error checking for negative numbers
        if(N < 0)
        {
            outfile << setw(3) << N << setw(15) << '-' << setw(15) 
                    << '-' << setw(15) << '-' << endl;
        }
        
        // Print out row of case
        else
            outfile << setw(3) << N << setw(15) << loopSum(N) << setw(15) 
                    << recSum(N) << setw(15) << closed(N) << endl;
    }

    // Close the input/output files
    closeFiles(infile, outfile);

    return 0;

}

// openFiles definition
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
    cout << "Beginning processing..." << endl;
}

// loopSum definition
int loopSum(int n)
{
    int total = 0;

    // Sum squares via for loop
    for(int k = 1; k <= n; k++)
    {
        total += pow(k,2);
    }

    return total;
}

// recSum function definition
int recSum(int n)
{
    // Early exit conditional for 0
    if(n == 0)
        return 0;

    // Base case for 1
    else if(n == 1)
        return 1;

    // Recursive call
    else   
        return pow(n,2) + recSum(n - 1);
}

// closed function definition
int closed(int n)
{
    // Returns the number calculated by the closed form solution
    return (n*(n+1)*(2*n+1))/6;
}

// closeFiles function definition
void closeFiles(ifstream& infile, ofstream& outfile)
{
    cout << "Processing complete, closing files..." << endl;
    infile.close();
    outfile.close();
    cout << "Files closed, program has finished." << endl;
    
}