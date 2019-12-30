// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 7 - Problem 1: User
#include <iostream>
#include "User.h"
using namespace std;

// Implementation of User class

User::User()
{
    username = "";
    numRatings = 0;
    size = 50;
    ratings[50];
    for(int i = 0; i < size; i++) // Fills rating array with 0's
    {
        ratings[i] = 0;
    }
}

User::User(string s, int arr[], int i)
{
    username = s;
    size = 50;
    numRatings = i;
    ratings[50];
    for(int i = 0; i < size; i++) // Fills rating array with 0's
    {
        ratings[i] = 0;
    }
    for(int i = 0; i < numRatings; i++) // Fills rating array with given array
    {
        ratings[i] = arr[i];
    }
    
}

string User::getUsername()
{
    return username;
}

void User::setUsername(string s)
{
    username = s;
}

int User::getRatingAt(int index)
{
    if(index >= size || index < 0)
    {
        return -1;
    }
    else
    {
        return ratings[index];
    }
}

bool User::setRatingAt(int index, int value)
{
    if(index < 50 && index >= 0 && value >= 0 && value <= 5)
    {
        ratings[index] = value;
        return true;
    }
    else
    {
        return false;
    }
    
}

int User::getNumRatings()
{
    return numRatings;
}

void User::setNumRatings(int i)
{
    numRatings = i;
}

int User::getSize()
{
    return size;
}