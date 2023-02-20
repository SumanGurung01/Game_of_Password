/*
    Date : Mon Feb 20 2023 13:47:07 GMT+0530 (India Standard Time)
    Author : Suman Gurung
    Description : The Game of Password
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;
#define N 10;

void welcome()
{
    cout << "\n*** WELCOME TO PASSWORD GAME ***" << endl;
    cout << "\nOBJECTIVE : To correctly guess the password within 10 try" << endl;
}

int difficulty_selection()
{
    int difficulty = 0;
    int password_length = 0;
    while (true)
    {
        cout << "\nChoose Difficulty Level\n1. Easy\t\t2. Medium\t3. Hard\t\t4. Extreme\nYour Choice : ";
        cin >> difficulty;

        if (difficulty == 1)
        {
            password_length = 4;
            break;
        }
        if (difficulty == 2)
        {
            password_length = 5;
            break;
        }
        if (difficulty == 3)
        {
            password_length = 6;
            break;
        }
        if (difficulty == 4)
        {
            password_length = 7;
            break;
        }

        cout << "\n---\tInvalid Difficulty Choosen. Please Try Again\t---" << endl;
    }

    return password_length;
}

int check(int password[], int guess[], int length)
{
    int correct, incorrect = 0;

    for (int i = 0; i < length; i++)
    {
        if (password[i] == guess[i])
        {
            correct++;
            cout << password[i] << " ";
        }
        else
        {
            cout << "* ";
        }
    }

    incorrect = length - correct;

    if (incorrect == 0)
        return 1;

    cout << endl;
    cout << correct << " : Correctly Placed\t " << incorrect << " : Incorrectly Placed\n ";

    return 0;
}

int main()
{
    welcome();

    int password_length = difficulty_selection();

    int password[password_length];
    int guess[password_length];
    memset(guess, -1, sizeof(guess));

    srand((unsigned)time(NULL));

    int found = 0;

    for (int i = 0; i < password_length; i++)
    {
        password[i] = rand() % N;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "\n--------------------------------------------------------------------\n";
        cout << "\nEnter " << password_length << " Digit Password : ";

        for (int j = 0; j < password_length; j++)
        {
            cin >> guess[j];
        }

        found = check(password, guess, password_length);
        if (found)
            break;
    }

    if (found)
    {
        cout << "\n\nYOU WIN\n";
    }
    else
    {
        cout << "\n\nGAMEOVER\n";
    }

    cout << "THE PASSWORD IS : ";
    for (int j = 0; j < password_length; j++)
    {
        cout << password[j] << " ";
    }
}