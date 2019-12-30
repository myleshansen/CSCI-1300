// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 7 - Problem 3: getRating
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
 * Algorithm: Givern a usernam and book title, return the rating the user gave that book
 * 1. Loop through the users and check if it exists
 * 2. Loop through the books and make sure it exists
 * 3. If they dont exist, return -3
 * 4. If they do, return the rating
 * Input parameters: string username, string title, User array, Book array, integer number of users, integer number of books
 * Output (prints to screen): Nothing
 * Returns: Rating given to the book
*/
int getRating(string username, string title, User users[], Book books[], int numUsers, int numBooks)
{
    bool t1 = false;
    bool t2 = false;
    int temp = 0;
    int temp2 = 0;
    
    for(int i = 0; i < numUsers; i++)
    {
        if(to_lower(users[i].getUsername()) == to_lower(username)) // Check if username exists
        {
            t1 = true;
            temp = i;
            break;
        }
        
        
    }
    
    for(int i = 0; i < numBooks; i++)
    {
        if(to_lower(books[i].getTitle()) == to_lower(title)) // Check if book exists
        {
            
            t2 = true;
            temp2 = i;
            break;
        }
    }
    
    if(t1 == false || t2 == false) // If either dont exist
    {
        return -3;
    }
    else
    {
        return users[temp].getRatingAt(temp2);
    }
}

int main()
{
    // Test 1
    // Expected output
    /*
        1
    */
    cout<<getRating("Tom", "The Fountainhead", users, books, 5, 4)<<endl;
    
    // Test 2 
    // Expected output
    /*
        5
    */
    cout<<getRating("Daniel", "Three Men In A Boat", users, books, 5, 4)<<endl;
    
    // Test 3 
    // Expected output
    /*
        -3
    */
    cout<<getRating("Hugh", "Three Men In A Boat", users, books, 5, 4)<<endl;
}