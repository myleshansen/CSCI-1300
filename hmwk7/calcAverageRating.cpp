// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 7 - Problem 5: calcAverageRating
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
 * Algorithm: Calculates the mean rating for a book
 * 1. Check if the book exists
 * 2. If so, loop through users and add up how many ratings were given
 * 3. If the book exists, calculate mean and return
 * Input parameters: User array, Book array, integer number of users, integer number of books, string title
 * Output (prints to screen): Nothing
 * Returns: Mean average of ratings for a book
*/
double calcAverageRating(User users[], Book books[], int numUsers, int numBooks, string title)
{
    double count = 0;
    double total = 0;
    bool exists = false;
    int temp = 0;
    for(int i = 0; i < numBooks; i++)
    {
        if(to_lower(books[i].getTitle()) == to_lower(title)) // Check if book title exists
        {
            exists = true;
            temp = i;
        }
    }
    for(int i = 0; i < numUsers; i++)
    {
        if(users[i].getRatingAt(temp) == 0)
        {
            continue;
        }
        else
        {
            total += users[i].getRatingAt(temp); // Add up total of ratings
            count++; // Add up number of ratings
        }
    }
    
    if(exists == false || numUsers < 1)
    {
        return -3;
    }
    else
    {
        if(count == 0)
        {
            return 0;
        }
        else
        {
            return total / count; // Return mean
        }
    }
}

int main()
{
    // Test 1
    // Expected output
    /*
        3.75
    */
    cout << calcAverageRating(users,books,5,4,"furioUsly haPpy") <<endl;
    
    // Test 2 
    // Expected output
    /*
        -3
    */
    cout << calcAverageRating(users,books,5,4,"Harry Potter") <<endl;
}