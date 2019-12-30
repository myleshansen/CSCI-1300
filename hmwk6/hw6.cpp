// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 6 - Problem 7: hw6

#include <iostream>
#include <fstream>
using namespace std;

class Book {
    private:
    string title;
    string author;
    
    public:
    Book();
    Book(string t, string a);
    string getTitle();
    void setTitle(string t);
    string getAuthor();
    void setAuthor(string a);
};

Book::Book()
{
    title = "";
    author = "";
}

Book::Book(string t, string a)
{
    title = t;
    author = a;
}

string Book::getTitle()
{
    return title;
}

void Book::setTitle(string t)
{
    title = t;
}

string Book::getAuthor()
{
    return author;
}

void Book::setAuthor(string a)
{
    author = a;
}

void printBooksByAuthor(Book books[], int booksNum, string author)
{
    if(booksNum <= 0)
    {
        cout << "No books are stored" << endl;
    }
    else
    {
        string temp[booksNum];
        int count = 0;
        for(int i = 0; i < booksNum; i++) // Loop through books and check if book by author
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

void printAllBooks(Book books[], int booksNum)
{
    if(booksNum <= 0) // If there are no books
    {
        cout << "No books are stored" << endl;
    }
    else
    {
        cout << "Here is a list of books" << endl;
        for(int i = 0; i < booksNum; i++) // Loop through books and print each
        {
            if(books[i].getTitle() == "")
            {
                continue;
            }
            else
            {
                cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
            }
        }
    }
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
 * Algorithm: Stores name of books in an array
 * 1. Open file and check if it exists
 * 2. If file exists, loop through file
 * 3. While file is still open, add each line to array and return length
 * Input parameters: string filename, array of titles, array of authors, integer of books, integer size
 * Output (prints to screen): Nothing
 * Returns: Size of array
*/
int readBooks(string fileName, Book books[], int numBookStored, int size)
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
                books[index].setTitle(temp[1]); // Add books
                books[index].setAuthor(temp[0]);
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

void printMenu(){
    cout << "======Main Menu=====" << endl;
    cout << "1. Read books" << endl;
    cout << "2. Print all books" << endl;
    cout << "3. Print books by author" << endl;
    cout << "4. Quit" << endl;
}

int main()
{
    string input;
    string author;
    string fileName;
    Book books[50];
    int total = 0;
    int temp = 0;
    while(input != "4")
    {
        printMenu();
        cin >> input;
        if(input == "1")
        {
            cout << "Enter a book file name: ";
            cin >> fileName;
            cout << endl;
            temp = total;
            total = readBooks(fileName, books, temp, 50);
            if(total > -1)
            {
                if(total >= 50)
                {
                    cout << "Database is full. Some books may have not been added." << endl;
                }
                else
                {
                    cout << "Total books in the database: " << total << endl;
                }
            }
            else if(total == -1)
            {
                cout << "No books saved to the database." << endl;
            }
            else 
            {
                cout << "Database is already full. No books were added." << endl;
            }
            
        }
        else if(input == "2")
        {
            printAllBooks(books, 50);
        }
        else if(input == "3")
        {
            cout << "Enter name of author: ";
            cin.ignore(1000, '\n');
            getline(cin, author);
            cout << endl;
            printBooksByAuthor(books, 50, author);
        }
        else
        {
            if(input == "4")
            {
                break;
            }
            else
            {
                cout << "Invalid input." << endl;
            }
        }
    }
    cout << "Good bye!";
}