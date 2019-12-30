// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 6 - Problem 3: Book

#include <iostream>
using namespace std;

#ifndef BOOK_H
#define BOOK_H

/*
Book class that allows you to set and get title and author
*/

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

#endif