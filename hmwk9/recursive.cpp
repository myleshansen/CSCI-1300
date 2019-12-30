// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 9 - Problem 2: recursion!

#include <iostream>
using namespace std;

/*
 * Algorithm: Convert an integer to its binary number
 * 1. Check if the input number is greater than 1
 * 2. If so, find the remainder and recall the function with the input number divided by 2
 * 3. Do this until the input number equals 1 or 0, then return 1 or 0
 * Input parameters: integer number to be converted
 * Output (prints to screen): Nothing
 * Returns: Binary Number
 */
string decimalToBinaryRecursive(int binary)
{
    int temp = binary;
    if(temp > 1) // Base case
    {
        string final = to_string(temp % 2); // Remainder
        return decimalToBinaryRecursive(temp / 2) + final; // Final remainder plus remainder of previous loops
    }
    else
    {
        return to_string(binary); // Base case return statement
    }
}

int main()
{
    // Test 1
    // Expected Output
    // 11010
    cout << decimalToBinaryRecursive(26) << endl;
    
    // Test 2
    // Expected Output
    // 0
    cout << decimalToBinaryRecursive(0) << endl;
}