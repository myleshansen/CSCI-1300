// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 4 - Problem 6: split
#include <iostream>
using namespace std;

/*
 * Algorithm: 
 * 1. Check if string is empty
 * 2. If not, loop through string
 * 3. If the character in string does not equal the delimeter add it to temp string
 * 4. Else, add string to array if it is not the delimeter
 * Input parameters: string sentence, char delimeter, string array, integer length
 * Output (prints to screen): Nothing
 * Returns: Words in array seperated by delimeter
 */
 
int split(string s, char delim, string words[], int len)
{
    string temp = ""; // Temp string
    int count= 0;
    if(s == "") // If string is empty return 0
    {
        return 0;
    }
    else
    {
        s += delim;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != delim) // If string is not delim add to temp string
            {
                temp += s[i];
            }
            else
            {
                if(temp == "") // If temp string is empty, move on
                {
                    continue;
                }
                else
                {
                    words[count] = temp; // Add temp string to array of words
                    temp = "";
                    count++;
                }
                
            }
        }
    }
    return count;
}

int main()
{
    // Test 1
    // Expected output
    // 3
    string words[6];
    cout << split("one small step",' ',words,6) << endl;
    // Test 2
    // Expected output
    // 0
    string words2[0];
    cout << split("",' ',words,0);
    
}