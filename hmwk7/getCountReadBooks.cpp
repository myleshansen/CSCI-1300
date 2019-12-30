// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 7 - Problem 4: getCountReadBooks
#include <iostream>
#include User.h
#include Book.h
using namespace std;

/*
 * Algorithm: Convert capital characters in a string to lowercase
 * 1. Check to makes sure character is capital
 * 2. If it is, add 32 to the character to the code of the lowercase versioon of the letter
 * Input parameters: Character from a string
 * Output (prints to screen): Nothing
 * Returns: Lowercase character
*/
char toLower(char c)
{
    if (c >= 'A' && c <= 'Z')
		return c + 32;

	return c;
}

/*
 * Algorithm: Convert each letter of a string to lowercase
 * 1. Loop through string
 * 2. Call the toLower function to convert character to lowercase and add to string
 * Input parameters: String
 * Output (prints to screen): Nothing
 * Returns: Lowercase string
*/
string to_lower(string s)
{
    string temp = "";
    for(int i = 0; i < s.size(); i++)
    {
        temp += toLower(s[i]);
    }
    return temp;
}

/*
 * Algorithm: Returns how many books a user rated
 * 1. Check if the specified user exists
 * 2. Loop through books and check if user rated it
 * 3. If the user exists, return the number of books rated
 * Input parameters: String username, User array, integer number of users, integer number of books
 * Output (prints to screen): Nothing
 * Returns: Number of books rated
*/
int getCountReadBooks(string username, User users[], int numUsers, int numBooks)
{
    int count = 0;
    bool exists = false;
    int temp = 0;
    for(int i = 0; i < numUsers; i++)
    {
        if(to_lower(username) == to_lower(users[i].getUsername()) && numBooks > 0) // Check if book exists
        {
            exists = true;
            temp = i;
        }
    }
    
    for(int i = 0; i < numBooks; i++)
    {
        if(users[temp].getRatingAt(i) > 0)
        {
            count++; // Add up ratings
        }
    }
    
    if(exists == true)
    {
        return count;
    }
    else // If username doesnt exists
    {
        return -3;
    }
    
}

int main()
{
    // Test 1
    // Expected output
    /*
        2
    */
    cout << getCountReadBooks("emma",users,5,4) <<endl;
    
    // Test 2 
    // Expected output
    /*
        -3
    */
    cout << getCountReadBooks("Punith",users,5,4) <<endl;
}