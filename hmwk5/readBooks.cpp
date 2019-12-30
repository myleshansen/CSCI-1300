// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 5 - Problem 2: readBooks
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
 * Algorithm: Stores name of books in an array
 * 1. Open file and check if it exists
 * 2. If file exists, loop through file
 * 3. While file is still open, add each line to array and return length
 * Input parameters: string filename, array of titles, array of authors, integer of books, integer size
 * Output (prints to screen): Nothing
 * Returns: Size of array
*/
int readBooks(string fileName, string titles[], string authors[], int numBookStored, int size)
{
    ifstream myfile;
    myfile.open(fileName); // Open file
    
    if(myfile.is_open())
    {
        string temp[2];
        string line = "";
        int index = numBookStored;
        while(getline(myfile,line)) // Loop through file
        {
            if(line == "") // If line is empty, skip
            {
                continue;
            }
            else if(numBookStored == size) 
            {
                return -2;
            }
            else if(index >= size)
            {
                break;
            }
            else
            {
                split(line, ',', temp, 2); // Split each book by a ","
                titles[index] = temp[1]; // Add books
                authors[index] = temp[0];
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
    // 50
    string titles[50];
    string authors[50];
    cout << readBooks("books.txt", titles, authors, 0, 50) << endl;
    
    // Test 2
    // Expected Output
    // 25
    string titles2[50];
    string authors2[50];
    cout << readBooks("books.txt", titles, authors, 0, 25) << endl;
    
    // Test 3
    // Expected Output
    // -1
    string titles3[50];
    string authors3[50];
    cout << readBooks("bookss.txt", titles, authors, 0, 50) << endl;
}