// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 1 - Problem 2: printCharInString
#include <iostream>
using namespace std;

/*
 * Algorithm: Compute how many time a substring appears in a string
 * 1. Check if either string length is zero
 * 2. Iterate through string and check if substring matches
 * 3. If it does, increase count
 * 4. Return count
 * Input parameters: a string and asubstring
 * Output (prints to screen): nothing
 * Returns: Number of matches
 */
int countMatches(string final, string sub)
{
    if(sub.length() == 0 || final.length() == 0)
    {
        return -1;
    }
    else
    {
        int count  = 0;
        for(int i = 0; i < final.length(); i++)
        {
            if(final.substr(i,sub.length()) == sub)
            {
                count += 1;
            }
        }
        return count;
    }
}

int main()
{
    // test 1
    // expected output
    // 2
    cout << countMatches("mississippi", "si") << endl;
    
    // test 2
    // expected output
    // 1
    cout << countMatches("mississippi", "ipp");
}