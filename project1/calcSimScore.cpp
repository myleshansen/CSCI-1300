// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 1 - Problem 4: printCharInString
#include <iostream>
using namespace std;

/*
 * Algorithm: Calculate similarity scores of sequences
 * 1. Take sequences
 * 2. Check if either equal 0 or if they are not equal
 * 3. If not, loop through string
 * 4. If a letter does not equal, increasing hamming distance
 * 5. Return similarity score
 * Input parameters: 2 string sequences
 * Output (prints to screen): Nothing
 * Returns: Similarity score of sequences
 */
double calcSimScore(string sequence1, string sequence2)
{
    double length = sequence1.length();
    double hammingDistance;
    if (length != sequence2.length() || length == 0)
    {
        return 0;
    }
    else
    {
        for(int i = 0; i < length; i++)
        {
            if(sequence1[i] != sequence2[i])
            {
                hammingDistance += 1;
            }
        }
        return (length - hammingDistance) / length;
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