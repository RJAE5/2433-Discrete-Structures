/************************************************************************
*
*  Author:           Rykir Evans
*  Email:            rjevans0408@my.msutexas.edu
*  Label:            P01
*  Title:            Bitwise Operations
*  Course:           CMPS 2433 Discrete Structures
*  Professor:        Catherine Stringfellow
*  Semester:         Fall 2024
*
*  Description:      This program reads in a list of integers and
*                    does bitwise manipulation to achieve the index
*                    of the highest set bit within any integer. It
*                    proceeds to modify the original number by
*                    setting the next highest bit to a 1 using
*                    logical OR and displays the original integer,
*                    the index of it's highest bit, and the modified
*                    integer to an output file.
*         
*
*  Usage:            You may edit the list of input values to determine
*                    the index of their highest bit, and the potential
*                    value if the next highest bit were set to 1.
*        
*       
*
*  Files:             main.cpp
*                     HighBits.dat
*                     Output.dat
************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Function prototypes
int findHigh(int k);                        
int modHigh(int k, int index);


int main()
{
    // Create file readers/printers
    ifstream infile;
    ofstream outfile;

    // Open in & out files
    infile.open("HighBits.dat");
    outfile.open("Output.dat");

    // Read in number of test cases
    int testCases;
    infile >> testCases;

    // Header information for assignment
    outfile << "Rykir Evans" << endl
            << "Highest Bit Program 1" << endl << endl
            << "There are " << testCases << " test cases." << endl << endl;

    // Header information for table display
    outfile << "k " << " HighestBit" << " k2" << endl 
            << setfill('-') << setw(20) << " " << endl << setfill(' ');

    // Number to read in
    int new_k; 

    // Process infile, displaying k, index of it's highest bit, and k2
    while(infile >> new_k)                  
        {
            int index = findHigh(new_k);
            outfile << left << setw(8) << new_k << setw(5) << index
                    << setw(8) << modHigh(new_k, index) << endl;
        }

    // Close files
    infile.close();
    outfile.close();
}// End main


/*
 * findHigh
 *
 * Description:
 *      Recieves an integer and finds the index of the
 *      highest set bit within this integer
 *
 * Params:
 *  int - The integer to do bitwise processes with
 *
 * Returns:
 *  int - The index of the highest set bit within the integer
 */
int findHigh(int k)
{
    // Early exit conditional for 0
    if(k == 0)                              
        return -1;

    int index = 0;

    // Logical shift right on k till it is 0
    do                                     
    {
        k = k >> 1;
        index++;
    }while(k != 0);

    // Return index of highest bit
    return index;                           
}// End findHigh


/*
 * modHigh
 *
 * Description:
 *      Uses the index of the highest set bit within k
 *      to modify the second highest bit to a 1
 *
 * Params:
 *  int - The integer to do bitwise processes with
 *  int - The index of the highest set bit within k
 *
 * Returns:
 *  int - The modified number with k's second highest bit set to 1
 */
int modHigh(int k, int index)
{
    // Travel bit
    int tempk = 1;                          

    // Move travel bit to index before highest bit
    for(int i = 0; i < index; i++)          
    {                                       
        tempk = tempk << 1;
    }

    // Logical OR to achieve number with next highest bit set
    int k2 = tempk | k;                     
    

    return k2;
}// End modHigh