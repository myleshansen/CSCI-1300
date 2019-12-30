// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 3 - Problem 10: printGrind

#include <iostream>
using namespace std;

/*
 * Algorithm: Print grid according to size
 * 1. If size is less than or equal to 0 print statement
 * 2. Iterate through input size column and rows of ascii art
 * 3. Add one extra row at the end
 * Input parameters: Size of grid
 * Output (prints to screen): Grid
 * Returns: nothing
 */
void printGrid(int size)
{
    if(size <= 0)
    {
        cout << "The grid can only have a positive number of rows and columns.";
    }
    else
    {
        for(int j = 0; j < size; j++)
        {
            for(int j = 0; j < size; j++)
            {
                cout << "+--";
            }
            cout << "+" <<endl;
            for(int j = 0; j < size; j++)
            {
                cout << "|  ";
            }
            cout << "|" << endl;
        }
        for(int i = 0; i < size; i++)
            {
                cout << "+--";
            }
            cout << "+";
    }
}

int main() 
{
    // Test 1
    // Expected output
    // The grid can only have a positive number of rows and columns.
    printGrid(0);
    
    // Test 2
    // Expected output
    /*
    +--+--+--+--+
    |  |  |  |  |
    +--+--+--+--+
    |  |  |  |  |
    +--+--+--+--+
    |  |  |  |  |
    +--+--+--+--+
    |  |  |  |  |
    +--+--+--+--+
    */
    printGrid(4);
}