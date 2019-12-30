// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 6 - Problem 3: Book
#include <iostream>
#include "Book.h"
using namespace std;

// Implementation of Book class

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