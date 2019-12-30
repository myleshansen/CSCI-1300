// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Homework 8 - Problem 1: vector fun

#include <iostream>
using namespace std;

/*
 * Algorithm: Combine and shuffle vector contents
 * 1. Check if either vector is bigger than the other
 * 2. If so, alternate adding values to a new vector
 * 3. If they are the same size, return combined values
 * 4. If they are empty return an empty vector
 * Input parameters: vector 1 and vector 2
 * Output (prints to screen): Nothing
 * Returns: New combined vector
 */
vector<int> shuffle(vector<int> v1, vector<int> v2)
{
    vector<int> temp;
    int count1 = 0;
    int count2 = 0;
    if(v1.size() < v2.size())
    {
        for(int i = 0; i < v1.size() + v2.size(); i++)
        {
            if(i % 2 == 0)
            {
                temp.push_back(v2[count2]);
                count2++;
            }
            else
            {
                if(v1.size() == 0 || count1 >= v1.size())
                {
                    temp.push_back(v2[count2]);
                    count2++;
                }
                else
                {
                    temp.push_back(v1[count1]);
                    count1++;
                }
            }
        }
        return temp;
    }
    else if(v2.size() < v1.size())
    {
        for(int i = 0; i < v1.size() + v2.size(); i++)
        {
            if(i % 2 == 0)
            {
                temp.push_back(v1[count1]);
                count1++;
            }
            else
            {
                if(v2.size() == 0 || count2 >= v2.size())
                {
                    temp.push_back(v1[count1]);
                    count1++;
                }
                else
                {
                    temp.push_back(v2[count2]);
                    count2++;
                }
            }
        }
        return temp;
    }
    else if(v1.size() == 0 && v2.size() == 0)
    {
        return v1;
    }
    else
    {
        for(int i = 0; i < v1.size() + v2.size(); i++)
        {
            if(i % 2 == 0)
            {
                temp.push_back(v1[count1]);
                count1++;
            }
            else
            {
                temp.push_back(v2[count2]);
                count2++;
            }
        }
        return temp;
    }
}

int main()
{
    // Test 1
    // Expected output
    /*
        2 1 4 3 6 5 8 9 10
    */
    vector<int> v1{1,3,5,9};
    vector<int> v2{2,4,6,8,10};
    vector<int> v3 = shuffle(v1,v2);
    for (int i=0; i < v3.size(); i++) {
    cout << v3[i] << " ";
}
    
    // Test 2
    // Expected output
    /*
        1 5 3 -7
    */
    vector<int> v4{1,3};
    vector<int> v5{5,-7};
    vector<int> v6 = shuffle(v4,v5);
    for (int i=0; i < v6.size(); i++) {
        cout << v6[i] << " ";
    }
    
    // Test 3
    // Expected output
    /*
    
    */
    vector<int> v7;
    vector<int> v8;
    vector<int> v9 = shuffle(v7,v8);
    for (int i=0; i < v9.size(); i++) {
        cout << v9[i] << " ";
    }
}