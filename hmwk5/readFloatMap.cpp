// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 5 - Problem 6: readFloatMap
#include <iostream>
#include <fstream>
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

/*
 * Algorithm: Prints contents of a 2D array
 * 1. Open file
 * 2. If file is open, loop through
 * 3. Check if line contains a "," if so, split line
 * 4. Add each item to 2D array
 * Input parameters: String sentence, character delimeter, string array of words, integer length
 * Output (prints to screen): Nothing
 * Returns: Size of array
*/
int readFloatMap(string fileName, double arr[][4], int rows)
{
    ifstream myfile;
    myfile.open(fileName); // Open file
    string temp[4];
    double temp2[4];
    if(myfile.is_open()) // Check if file is open
    {
        string line = "";
        int index = 0;
        while(getline(myfile, line)) // Loop through file
        {
            split(line, ',', temp, 4);
            if(line == "")
            {
                continue;
            }
            else
            {
                for(int i = 0; i < 4; i++) // Loop through the split array and cast to integer
                {
                    arr[index][i] = stod(temp[i]);
                }
                index++;
            }
        }
        return index;
    }
    else
    {
        return -1;
    }
}

int main()
{
    // Test 1
    // Expected Output
    // -1
    double floatMap[2][4];
    cout << readFloatMap("DNEFile.txt", floatMap, 2) << endl;
    // Test 2
    // Expected Output
    // 4
    double floatMap2[4][4];
    cout << readFloatMap("floodMap.txt", floatMap2, 2);

}