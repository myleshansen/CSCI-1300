// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 3 - Problem 4: countDigits

#include <iostream>
using namespace std;

/*
 * Algorithm: Counts amount of digits inputted
 * 1. Take in integer
 * 2. Multiply integer by -1 if its is less than 0
 * 3. Convert to string
 * 4. Return size of string
 * Input parameters: integer
 * Output (prints to screen): nothing
 * Returns: length of string
 */
int countDigits(int n)
{
    if(n < 0) {
        n = n * -1;
    }
    string a = to_string(n);
    
    return a.size();
}

int main() 
{
    // Test 1
    // Expected output
    // 3
    cout << countDigits(123) << endl;
    
    // Test 2
    // Expected output
    // 4
    cout << countDigits(1234);
}