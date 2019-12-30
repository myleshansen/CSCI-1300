// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 7 - Problem 2: readRatings
#include <iostream>
#include User.h
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
 * Input parameters: string file name, User array, integer users, integer size of user array, integer columns
 * Output (prints to screen): Nothing
 * Returns: Amount of users
*/
int readRatings(string fileName, User users[], int numUsersStored, int usersArrSize, int maxCol)
{
    if(numUsersStored >= usersArrSize)
    {
        return -2;
    }
    
    ifstream myfile;
    myfile.open(fileName); // Open file
    if(myfile.is_open()) // Check if file is open
    {
        string line = "";
        int index = numUsersStored;
        string temp[maxCol + 1];
        int tempIndex = 0;
        while(getline(myfile, line)) // Loop through file
        {
            if(line == "")
            {
                continue;
            }
            else if(index >= usersArrSize)
            {
                return usersArrSize;
            }
            else
            {
                split(line, ',', temp, maxCol + 1); // Split sentence by "," into an array
                users[index].setUsername(temp[0]);
                for(int i = 0; i < maxCol; i++) // Loop through array
                {
                    if(temp[i + 1] == "") // Check if line is empty
                    {
                        break;
                    }
                    else
                    {
                        users[index].setRatingAt(i, stoi(temp[i + 1])); // Add rating and cast to integer
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
    // Expected output
    /*
        -1
    */
    User users[10];

    int numUsers = 0;
    int maxRows = 10;
    int maxColumns = 50;
    readRatings("ratings.txt", users, numUsers, maxRows, maxColumns);
    
    // Test 2 
    // Expected output
    /*
        4
    */
    User users2[10] = {};

    int numUsers2 = 0;
    int maxRows2 = 10;
    int maxColumns2 = 50;
    int numBooks2 = 5;
    numUsers2 = readRatings("ratings_sample1.txt", users2, numUsers2, maxRows2, maxColumns2);
}