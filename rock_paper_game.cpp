#include <bits/stdc++.h>
#include <string>
#include <iomanip>
#include <windows.h>
#include <conio.h>

using namespace std;

int user(int c)
{
    int s;
    switch (c)
    {
    case 1:
        s = 1;
        break;
    case 2:
        s = 2;
        break;
    case 3:
        s = 3;
        break;
    default:
        cout << "Invalid input!!";
    }
    return s;
}

void settextcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

string computer_choice(int s2)
{
    string s3;
    switch (s2)
    {
    case 1:
        s3 = "Rock";
        break;
    case 2:
        s3 = "Paper";
        break;
    case 3:
        s3 = "Scissors";
        break;
    }
    return s3;
}

string user_choice(int s1)
{
    string s4;
    switch (s1)
    {
    case 1:
        s4 = "Rock";
        break;
    case 2:
        s4 = "Paper";
        break;
    case 3:
        s4 = "Scissors";
        break;
    }
    return s4;
}

void welcome_page()
{
    settextcolor(4);
    cout << setw(70) << "Welcome To The Game!" << "\n";

    cout << "\n";
    settextcolor(8);
    cout << setw(74) << "-- Press SPACE to continue--";
    while (true)
    {
        if (_kbhit())
        {
            char ch = _getch();
            if (ch == ' ')
                break;
        }
    }
    system("CLS");
}

bool run_game()
{
    int in;
    int count = 0;
    bool con = TRUE;
    while (con)
    {
        settextcolor(10);
        cout << setw(100) << "Ponits = " << count << "\n";
        settextcolor(5);
        cout << setw(71) << "1. Rock " << "\n";
        cout << setw(72) << "2. Paper " << "\n";
        cout << setw(75) << "3. Scissors " << "\n";

        cout << "\n";
        settextcolor(3);
        cout << setw(75) << "Enter one option..: ";
        cin >> in;
        cout << "\n";
        int s1 = user(in);

        int s2 = rand() % 3 + 1;

        string s5 = user_choice(s1);
        string s6 = computer_choice(s2);

        cout << "\n";
        cout << "\n";
        settextcolor(7);
        cout << setw(75) << "Your choice     = " << s5 << "\n";

        cout << setw(75) << "Computer choice = " << s6 << "\n";

        bool won = false;
        if ((s1 == 1 && s2 == 3) || (s1 == 2 && s2 == 1) || (s1 == 3 && s2 == 2))
        {
            count++;
            won = true;
        }

        cout << "\n";
        cout << "\n";

        if (won)
        {
            settextcolor(10);
            cout << setw(76) << "You won this round!" << "\n";
        }
        else if (s1 == s2)
        {
            settextcolor(1);
            cout << setw(76) << "It's a draw!" << "\n";
        }
        else
        {
            settextcolor(12);
            cout << setw(76) << "You lost this round!" << "\n";
        }

        cout << "\n";
        cout << "\n";
        cout << "\n";
        settextcolor(2);
        cout << setw(85) << " -- Press ENTER to attempt again -- ";
        cout << "\n";
        cout << "\n";
        cout << setw(80) << " -- Press SPACE to RESTART -- ";
        while (true)
        {
            if (_kbhit())
            {
                char ch = _getch();
                if (ch == 13)
                    break;
                else if (ch = ' ')
                    con = FALSE;
                break;
            }
        }
        system("CLS");
    }
    return false;
}

int main()
{

    system("CLS");

    while (true)
    {
        welcome_page();
        if (!run_game())
        {
            continue;
        }
    }
}
