// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 5 - Problem 7: readRatings
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
 * Algorithm: Sorts ratings of books by users
 * 1. Open file
 * 2. If file is open, loop through
 * 3. If the line is empty, move on
 * 4. If not, loop through ratings and cast to integers
 * Input parameters: string file name, string array, integer 2D ratings array, integer users, integer rows, integer columns
 * Output (prints to screen): Nothing
 * Returns: Amount of users
*/
int readRatings(string fileName, string users[], int ratings[100][50], int numUsers, int maxRows, int maxColumns)
{
    if(numUsers == maxRows)
    {
        return -2;
    }
    
    ifstream myfile;
    myfile.open(fileName); // Open file
    if(myfile.is_open()) // Check if file is open
    {
        string line = "";
        int index = numUsers;
        string temp[maxColumns + 1];
        int tempIndex = 0;
        while(getline(myfile, line)) // Loop through file
        {
            if(line == "")
            {
                continue;
            }
            else if(index >= maxRows)
            {
                return maxRows;
            }
            else
            {
                split(line, ',', temp, maxColumns + 1); // Split sentence by "," into an array
                users[index] = temp[0];
                for(int i = 0; i < maxColumns; i++) // Loop through array
                {
                    if(temp[i + 1] == "") // Check if line is empty
                    {
                        break;
                    }
                    else
                    {
                        ratings[index][i] = stoi(temp[i + 1]); // Add rating and cast to integer
                    }  
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
    // 10
    string users[10] = {};
    int ratings[10][50] = {{0}};
    int numUsers = 0;
    int maxRows = 10;
    int maxColumns = 50;
    cout << readRatings("ratings.txt", users, ratings, numUsers, maxRows, maxColumns) << endl;
    
    // Test 2
    // Expected Output
    // 4
    string users2[10] = {};
    int ratings2[10][50] = {{0}};
    int numUsers2 = 0;
    int maxRows2 = 4;
    int maxColumns2 = 50;
    cout << readRatings("ratings.txt", users2, ratings2, numUsers2, maxRows2, maxColumns2);
}