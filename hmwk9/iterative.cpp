// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 9 - Problem 1: binary!

#include <iostream>
using namespace std;

/*
 * Algorithm: Convert an integer to its binary number
 * 1. Check if input equals 0 or 1
 * 2. If so, return them
 * 3. If not, loop through number until it equals 1 (dividing by 2)
 * 4. Add numbers to string
 * 5. Loop through string backwards and return backwards string
 * Input parameters: integer number to be converted
 * Output (prints to screen): Nothing
 * Returns: Binary Number
 */
string decimalToBinaryIterative(int binary)
{
    if(binary == 0 || binary == 1) // Base case
    {
        return to_string(binary);
    }
    string forward = "";
    int temp = binary;
    while(temp != 1) // Divide until temp equals 1
    {
        forward += to_string(temp % 2);
        temp /= 2;
    }
    forward += "1";
    
    string backward = "";
    for(int i = forward.length() - 1; i >= 0; i--) // Loop thorugh string backwards
    {
        backward += forward[i];
    }
    return backward;
}

int main()
{
    // Test 1
    // Expected Output
    // 11010
    cout << decimalToBinaryIterative(26) << endl;
    
    // Test 2
    // Expected Output
    // 0
    cout << decimalToBinaryIterative(0) << endl;
}