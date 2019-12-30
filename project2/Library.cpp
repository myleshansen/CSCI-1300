// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 2 - Problem 0: Library Class

#include <iostream>
#include <fstream>
#include "Library.h"
#include "Book.h"
#include "User.h"
using namespace std;

// Implementation of Library class

Library::Library()
{
    numBooks = 0;
    numUsers = 0;
}

int Library::getSizeBook()
{
    return sizeBook;
}

int Library::getSizeUser()
{
    return sizeUser;
}

int Library::getNumBooks()
{
    return numBooks;
}

int Library::getNumUsers()
{
    return numUsers;
}

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
 * Algorithm: Stores name of books in book array
 * 1. Open file and check if it exists
 * 2. If file exists, loop through file
 * 3. While file is still open, add each line to array and return length
 * Input parameters: string filename
 * Output (prints to screen): Nothing
 * Returns: Size of array
*/
int Library::readBooks(string fileName)
{
    ifstream myfile;
    myfile.open(fileName); // Open file
    if(numBooks == sizeBook) 
    {
        return -2;
    }
    if(myfile.is_open())
    {
        
        string temp[2];
        string line = "";
        while(getline(myfile,line)) // Loop through file
        {
            if(line == "") // If line is empty, skip
            {
                continue;
            }
            else if(numBooks >= sizeBook)
            {
                break;
            }
            else
            {
                split(line, ',', temp, 2); // Split each book by a ","
                books[numBooks].setTitle(temp[1]); // Add books
                books[numBooks].setAuthor(temp[0]);
                numBooks++;
            }
        }
        
        return numBooks;
    }
    else
    {
        return -1;   
    }
}

/*
 * Algorithm: Prints a list of books in array
 * 1. Check if array is empty
 * 2. If not, loop through array and print book and author
 * Input parameters:
 * Output (prints to screen): Title and author
 * Returns: Nothing
*/
void Library::printAllBooks()
{
    if(numBooks <= 0) // Make sure book array isnt empty
    {
        cout << "No books are stored." << endl;
    }
    else
    {
        cout << "Here is a list of books" << endl;
        for(int i = 0; i < sizeBook; i++) // Loop through book array
        {
            if(books[i].getTitle() == "")
            {
                break;
            }
            else // Print books
            {
                cout << books[i].getTitle() << " by ";
                cout << books[i].getAuthor() << endl;
            }
        }
    }
}

/*
 * Algorithm: Prints the books by a specific author
 * 1. Check if file is empty, if not loop through file
 * 2. Count books by author
 * 3. Print each book by author
 * Input parameters:string author name
 * Output (prints to screen): There are no books by , or Here is a list of books by
 * Returns: Nothing
*/
void Library::printBooksByAuthor(string author)
{
    if(numBooks <= 0)
    {
        cout << "There are no books by " << author << endl;
    }
    else
    {
        string temp[numBooks];
        int count = 0;
        for(int i = 0; i < numBooks; i++) // Loop through books and check if book by author
        {
            if(books[i].getAuthor() == author) // Check if book is by author
            {
                temp[count] = books[i].getTitle();
                count++;
            }
        }
        if(count == 0)
        {
            cout << "There are no books by " << author << endl;
        }
        else
        {
            cout << "Here is a list of books by " << author << endl;
            for(int i = 0; i < count; i++) // Print books by author
            {
                cout << temp[i] << endl;
            }
        }
    }
}

/*
 * Algorithm: Sorts ratings of books by users
 * 1. Open file
 * 2. If file is open, loop through
 * 3. If the line is empty, move on
 * 4. If not, loop through ratings and cast to integers
 * Input parameters: string file name
 * Output (prints to screen): Nothing
 * Returns: Amount of users
*/
int Library::readRatings(string filename)
{
    if(numUsers >= sizeUser)
    {
        return -2;
    }
    
    ifstream myfile;
    myfile.open(filename); // Open file
    if(myfile.is_open()) // Check if file is open
    {
        string line = "";
        string temp[100 + 1];
        int tempIndex = 0;
        while(getline(myfile, line)) // Loop through file
        {
            if(line == "")
            {
                continue;
            }
            else if(numUsers >= sizeUser)
            {
                return sizeUser;
            }
            else
            {
                split(line, ',', temp, 100 + 1); // Split sentence by "," into an array
                users[numUsers].setUsername(temp[0]);
                for(int i = 0; i < 100; i++) // Loop through array
                {
                    if(temp[i + 1] == "") // Check if line is empty
                    {
                        break;
                    }
                    else
                    {
                        users[numUsers].setRatingAt(i, stoi(temp[i + 1])); // Add rating and cast to integer
                    }  
                }
                numUsers++;
            }
        }
        return numUsers;
    }
    else
    {
        return -1;
    }
}


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
    if (c >= 'A' && c <= 'Z') // Check if char is a capital
    {
	    return c + 32;
    }
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
    for(int i = 0; i < s.size(); i++) // Loop through string
    {
        temp += toLower(s[i]);
    }
    return temp;
}

/*
 * Algorithm: Find rating of a book by a specific user
 * 1. Check if user exists
 * 2. Check if book exists
 * 3. If not, return -3
 * 4. If so, return rating at spot in array
 * Input parameters: string username and string book
 * Output (prints to screen): Nothing
 * Returns: Rating
 */
int Library::getRating(string username, string book)
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
        if(to_lower(books[i].getTitle()) == to_lower(book)) // Check if book exists
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
        return users[temp].getRatingAt(temp2); // Return rating
    }
}

/*
 * Algorithm: Returns how many books a user rated
 * 1. Check if the specified user exists
 * 2. Loop through books and check if user rated it
 * 3. If the user exists, return the number of books rated
 * Input parameters: string username
 * Output (prints to screen): Nothing
 * Returns: Number of books rated
*/
int Library::getCountReadBooks(string username)
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

/*
 * Algorithm: View the ratings by an author above a certain min ratings
 * 1. Check if user exists
 * 2. If so, loop through book array for user and find ratings
 * 3. Print out ratings above min ratings
 * Input parameters: string username, integer min rating
 * Output (prints to screen): Title and ratings
 * Returns: Nothing
 */
void Library::viewRatings(string username, int minRating)
{
    int index = 0;
    bool test = false;
    for(int i = 0; i < 100; i++)
    {
        if(to_lower(username) == to_lower(users[i].getUsername())) // Check if user exists
        {
            index = i;
            test = true;
            break;
        }
    }
    if(test == false) // If user does not exist
    {
        cout << username << " does not exist." << endl;
    }
    else
    {
        bool test2 = false;
        for(int i = 0; i < 50; i++)
        {
            if(books[i].getTitle() == "")
            {
                break;
            }
            else if(users[index].getRatingAt(i) >= minRating) // Make sure rating is above the min rating
            {
                test2 = true;
            }
        }
        if(test2 == false)
        {
            cout << username << " has not rated any books yet." << endl;
        }
        else
        {
            cout << "Here are the books that " << username << " rated" << endl;
            for(int i = 0; i < 50; i++)
            {
                if(users[index].getRatingAt(i) >= minRating) // Print out ratings above min rating
                {
                    cout << "Title : " << books[i].getTitle() << endl;
                    cout << "Rating : " << users[index].getRatingAt(i) << endl;
                    cout << "-----" << endl;
                }
            }
        }
    }
}

/*
 * Algorithm: Calculates the mean rating for a book
 * 1. Check if the book exists
 * 2. If so, loop through users and add up how many ratings were given
 * 3. If the book exists, calculate mean and return
 * Input parameters: string title
 * Output (prints to screen): Nothing
 * Returns: Mean average of ratings for a book
*/
double Library::calcAvgRating(string book)
{
    double count = 0;
    double total = 0;
    bool exists = false;
    int temp = 0;
    for(int i = 0; i < numBooks; i++)
    {
        if(to_lower(books[i].getTitle()) == to_lower(book)) // Check if book title exists
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

/*
 * Algorithm: Calculates the mean rating of an author
 * 1. Check if the author exists
 * 2. If so, loop through users and add up how many ratings were given
 * 3. If the author exists, calculate mean and return
 * Input parameters: string author
 * Output (prints to screen): Nothing
 * Returns: Mean average of ratings for an author
*/
double Library::calcAvgRatingByAuthor(string author)
{
    double count = 0;
    double total = 0;
    bool exists = false;
    int temp = 0;
    for(int i = 0; i < numBooks; i++)
    {
        if(to_lower(books[i].getAuthor()) == to_lower(author)) // Check if author exists
        {
            exists = true;
            temp = i;
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

/*
 * Algorithm: Add a user to the user array
 * 1. Check if suer array is full
 * 2. If not, chech if username is already in the array
 * 3. If not, add user to end of array
 * 4. Set deafult ratings to 0
 * Input parameters: string username
 * Output (prints to screen): Nothing
 * Returns: 1 0, or -2
 */
int Library::addUser(string username)
{
    int ratings[50];
    int temp = 0;
    if(users[99].getUsername() != "") // Check if user array is full
    {
        return -2;
    }
    for(int i = 0; i < sizeUser; i++)
    {
        if(to_lower(username) == to_lower(users[i].getUsername())) // Check if user already exists
        {
            return 0;
        }
        else if(users[i].getUsername() == "")
        {
            users[i] = User(username, ratings, 50); // Add user to array
            numUsers++;
            temp = i;
            break;
        }
    }
    for(int i = 0; i < sizeBook; i++)
    {
        users[temp].setRatingAt(i, 0); // Set rating default to 0
    }
    return 1;
}

/*
 * Algorithm: Update ratings of a book by a specific user
 * 1. Check if user exists
 * 2. Check if book exists
 * 3. If so, check if rating is within bounds
 * 4. If so, update rating for book
 * Input parameters: string username, string book title, integer rating
 * Output (prints to screen): Nothing
 * Returns: Success
 */
int Library::checkOutBook(string username, string book, int rating)
{
    int indexU = 0;
    int indexB = 0;
    bool u = false;
    bool b = false;
    for(int i = 0; i < sizeUser; i++)
    {
        if(to_lower(username) == to_lower(users[i].getUsername())) // Check if user exists
        {
            indexU = i;
            u = true;
        }
    }
    for(int i = 0; i < sizeBook; i++)
    {
        if(to_lower(book) == to_lower(books[i].getTitle())) // Check if title exists
        {
            indexB = i;
            b = true;
        }
    }
    if(rating >= 0 && rating <= 5)
    {
        if(u == false || b == false)
        {
            return -3;
        }
        else
        {
            users[indexU].setRatingAt(indexB, rating); // Update rating
        }
    }
    else
    {
        return -4;
    }
}

/*
 * Algorithm: Find book recomendations for a specific user
 * 1. Check if user exists
 * 2. If so, loop through users and calculate their similarity score
 * 3. Then, check if user has rated books
 * 4. If so, print out first 5 titles and authors
 * Input parameters: string username
 * Output (prints to screen): Recommended books
 * Returns: Nothing
 */
void Library::getRecommendations(string username)
{
    int indexU = 0;
    bool exist = false;
    
    for(int i = 0; i < sizeUser; i++)
    {
        if(to_lower(username) == to_lower(users[i].getUsername())) // Check if user exists
        {
            indexU = i;
            exist = true;
            break;
        }
    }
    
    if(exist == false)
    {
        cout << username << " does not exist." << endl;
    }
    else
    {
        int finalIndex = 0;
        int tempSim = 0;
        int counter = -1;
        int tester[sizeUser];
        for(int i = 0; i < sizeUser; i++)
        {
            counter++;
            if(i == indexU) // Skip user
            {
                tester[counter] = 0;
                continue;
            }
            else if(getCountReadBooks(to_lower(users[i].getUsername())) == 0) // Check if user has rated any books
            {
                tester[counter] = 0;
                continue;
            }
            else if(users[i].getUsername() == "")
            {
                break;
            }
            else
            {
                for(int j = 0; j < sizeBook; j++)
                {
                    if(books[j].getTitle() == "")
                    {
                        break;
                    }
                    else // Calculate similarity score
                    {
                        tempSim += (users[indexU].getRatingAt(j) - users[i].getRatingAt(j)) * (users[indexU].getRatingAt(j) - users[i].getRatingAt(j));
                    }
                }
                tester[counter] = tempSim;
                tempSim = 0;
            }
            
        }
        
        int low = 9999999;
        for(int j = 0; j < counter; j++) 
        {
            if(tester[j] < low && tester[j] != 0) // Find lowest similarity score
            {
                low = tester[j];
                finalIndex = j;
            }
        }
        
        int oCount= 0;
        for(int i = 0; i < sizeBook; i++)
        {
            if(users[finalIndex].getRatingAt(i) >= 3 && users[indexU].getRatingAt(i) == 0) // Make sure they have rated books
            {
                oCount++;
            }
        }
        
        if(oCount > 0)
        {
            int count = 0;
            cout << "Here is the list of recommendations" << endl;
            for(int i = 0; i < sizeBook; i++)
            {
                if(users[finalIndex].getRatingAt(i) >= 3 && users[indexU].getRatingAt(i) == 0)
                {
                    cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
                    count++;
                }
                else if(count == 5)
                {
                    break;
                }
            }
        }
        else
        {
            cout << "There are no recommendations for " << username <<" at present." << endl;;
        }
    }
}