// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 5 - Problem 5: floatMap
#include <iostream>
using namespace std;

/*
 * Algorithm: Prints whether number is above/below water level
 * 1. Loop through array
 * 2. Check if number is above or below water level
 * 3. If so print * / _
 * Input parameters: 
 * Output (prints to screen): 
 * Returns: 
*/

void floodMap(double arr[][4], int rows, double waterLevel)
{
    for(int i = 0; i < rows; i++) // Loop through 2D array
    {
        for(int j = 0; j < 4; j++)
        {
            if(arr[i][j] <= waterLevel) // If less print "*"
            {
                cout << "*";
            }
            else // If more print "_"
            {
                cout << "_";
            }
        }
        cout << endl;
    }
}

int main()
{
    // Test 1
    // Expected Output
    /*
    *_*_
    _*_*
    *_*_
    ***_
    */
    double map[4][4] = {{5.9064, 15.7541, 6.11483, 11.3928},
    {16.8498, 5.736, 9.33342, 6.36095},
    {3.18645, 16.935, 4.7506, 9.63635},
    {2.22407, 0.815145, 0.298158, 13.466}};
    floodMap(map, 4, 9.3);
    
    // Test 2
    // Expected Output
    // ____
    double map[1][4] = {9, 9, 9, 9};
    floodMap(map, 1, 0);
}