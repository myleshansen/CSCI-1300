// CS1300 Fall 2019
// Author: Myles Hansen
// Recitation: 202 - Joewie Koh
// Project 1 - Problem 6: findMatchedGenome
#include <iostream>
using namespace std;

/*
 * Algorithm: Compares genomes and evaluates which has the best match
 * 1. Take the set of 3 genomes and one sequence
 * 2. Check if any are empty, if so print warning
 * 4. Check if lengths of genomes are the same, if not print warning
 * 5. Else, iterate through genomes and compare to sequence
 * 6. Calculate and print which genomes are the best match
 * Input parameters: set of three string genomes and a string sequence
 * Output (prints to screen): Genome () is the best match.
 * Returns: Nothing
 */
void findMatchedGenome(string g1, string g2, string g3, string sequence)
{
    double hammingDistance;
    double length = g1.length();
    double score1 = 0;
    double score2 = 0;
    double score3 = 0;
    double tempScore = 0;
    
    if(g1.length() == 0 || g2.length() == 0 || g3.length() == 0 || sequence.length() == 0)
    {
        cout << "Genomes or sequence is empty.";
    }
    else if(g1.length() != g2.length() || g2.length() != g3.length() || g1.length() != g3.length())
    {
        cout << "Lengths of genomes are different.";
    }
    else
    {
        if(g1.length() == sequence.length())
        {
            for(int i = 0; i < length; i++)
            {
                if(g1[i] != sequence[i]) {
                    hammingDistance++;
                }
            }
            score1 = (length - hammingDistance) / length;
        }
        else
        {
            int temp;
            for(int i = 0; i < length - sequence.length() + 1; i++)
            {
                temp = i;
                for(int j = 0; j < sequence.length(); j++)
                {
                    if(g1[temp] != sequence[j])
                    {
                        hammingDistance++;
                    }
                    temp++;
                }
                tempScore = (sequence.length() - hammingDistance) / (double)sequence.length();
                if(tempScore > score1)
                {
                    score1 = tempScore;
                }
                hammingDistance = 0;
            }
        }
        
        
        if(g2.length() == sequence.length())
        {
            for(int i = 0; i < length; i++)
            {
                if(g2[i] != sequence[i]) {
                    hammingDistance++;
                }
            }
            score2 = (length - hammingDistance) / length;
        }
        else
        {
            int temp;
            for(int i = 0; i < length - sequence.length() + 1; i++)
            {
                temp = i;
                for(int j = 0; j < sequence.length(); j++)
                {
                    if(g2[temp] != sequence[j])
                    {
                        hammingDistance++;
                    }
                    temp++;
                }
                tempScore = (sequence.length() - hammingDistance) / (double)sequence.length();
                if(tempScore > score2)
                {
                    score2 = tempScore;
                }
                hammingDistance = 0;
            }
        }
        
        if(g3.length() == sequence.length())
        {
            for(int i = 0; i < length; i++)
            {
                if(g3[i] != sequence[i]) {
                    hammingDistance++;
                }
            }
            score3 = (length - hammingDistance) / length;
        }
        else
        {
            int temp;
            for(int i = 0; i < length - sequence.length() + 1; i++)
            {
                temp = i;
                for(int j = 0; j < sequence.length(); j++)
                {
                    if(g3[temp] != sequence[j])
                    {
                        hammingDistance++;
                    }
                    temp++;
                }
                tempScore = (sequence.length() - hammingDistance) / (double)sequence.length();
                if(tempScore > score3)
                {
                    score3 = tempScore;
                }
                hammingDistance = 0;
            }
        }
        if(score1 > score2)
        {
            if(score1 > score3)
            {
                cout << "Genome 1 is the best match." << endl;
            }
            else if(score3 > score1)
            {
                cout << "Genome 3 is the best match." << endl;
            }
            else if(score3 == score1)
            {
                cout << "Genome 1 is the best match." << endl;
                cout << "Genome 3 is the best match." << endl;
            }
        }
        else if(score1 > score3)
        {
            if(score1 > score2)
            {
                cout << "Genome 1 is the best match." << endl;
            }
            else if(score2 > score1)
            {
                cout << "Genome 2 is the best match." << endl;
            }
            else if(score2 == score1)
            {
                cout << "Genome 1 is the best match." << endl;
                cout << "Genome 2 is the best match." << endl;
            }
        }
        else if(score2 > score3 || score3 > score2)
        {
            if(score2 > score3)
            {
                cout << "Genome 2 is the best match." << endl;
            }
            else if(score3 > score2)
            {
                cout << "Genome 3 is the best match." << endl;
            }
        }
        else if(score2 == score3 && score1 != score2)
        {
            cout << "Genome 2 is the best match." << endl;
            cout << "Genome 3 is the best match." << endl;
        }
        else
        {
            cout << "Genome 1 is the best match." << endl;
            cout << "Genome 2 is the best match." << endl;
            cout << "Genome 3 is the best match." << endl;
        }
    }
}

int main()
{
    // test 1
    // expected output
    // Genome 1 is best match
    findMatchedGenome("TAAGGCA", "TCTGGGC", "CTAATAT", "AAG");
    
    // test 2
    // expected output
    // Genome 2 is best match
    findMatchedGenome("TAAGGCA", "TACCTAC", "AGCCAGA", "TCT");
}