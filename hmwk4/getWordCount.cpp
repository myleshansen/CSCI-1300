// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 4 - Problem 5: getWordCount
#include <iostream>
using namespace std;

/*
 * Algorithm: Calculate total number of words in a string
 * 1. If string is empty, return 0
 * 2. Else, count words in string seperated by a " "
 * Input parameters: string sentence
 * Output (prints to screen): Nothing
 * Returns: Words in string
 */
 
int getWordCount(string sentence)
{
    if(sentence.length() == 0) // If sentence length is 0 return 0
    {
        return 0;
    }
    else 
    {
        int count = 1; // Sy=tart at 1 to include last word
        for(int i = 0; i < sentence.length(); i++)
        {
            if(sentence[i] == ' ') // If there is a space count go up by 1
            {
                count++;
            }
        }
        return count;
    }
}

int main()
 {
   // Test 1
   // Expected output
   // 1
    cout << getWordCount("Go") << endl;
   // Test 2
   // Expected output
   // 0
   cout << getWordCount("");
 }