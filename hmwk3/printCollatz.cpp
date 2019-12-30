// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 3 - Problem 7: printCollatz

#include <iostream>
using namespace std;

/*
 * Algorithm: Prints collatz sequence
 * 1. Make sure input is greater than 0
 * 2. While input is greater than 1, prints collatz sequnce
 * 3. When input is 1, stop loop and add 1 to end of sequence
 * Input parameters: start of sequence
 * Output (prints to screen): collatz sequence
 * Returns: nothing
 */
void printCollatz(int start)
{
    int n = start;
    string full = "";
    if (n <= 0)
    {
        cout << "invalid number";
    }
    else
    {
        while(n != 1)
        {
            if(n % 2 == 0)
            {
                
                full += to_string(n) + " ";
                n /= 2;
            }
            else
            {
                full += to_string(n) + " ";
                n = n * 3 + 1;
            }
        }
        cout << full + "1";
    }
}

int main() 
{
    // Test 1
    // Expected output
    // 6 3 10 5 16 8 4 2 1
    printCollatz(6);
    
    // Test 2
    // Expected output
    // invalid number
    printCollatz(-3);
}