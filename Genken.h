#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int showDuelGenken(string name1, string name2);

string Choice[] = {"rock", "paper", "scissors"};

void Genken()
{
    cout << endl << endl;

    cout << "The next game is genken (rock, paper, scissors). The game will start with the last person.\n";
    usleep(3000000);
    cout << "The game is played until one player is eliminated and then goes on to the next until only one winner remains.\n";
    usleep(3000000);
    cout << "Press any key to start the game... " << endl;
    _getch();

    srand(time(NULL));

    for (int i = Players.size() - 1 ; i > 0; i--) { // Starting in descending order
        if (Players.size() == 1) // Winning condition
            goto WINNER;

        string FirstPlayer  = Competitors.getCompetitorName(Players[i]);
        bool stop = false;

        for (int j = i - 1, Winstreak = 0; j >= 0 && stop == false; j--) {
            string SecondPlayer = Competitors.getCompetitorName(Players[j]);
            usleep(1000000);

            int result = showDuelGenken(FirstPlayer, SecondPlayer);
            usleep(1000000);

            if (result == 1) { // If the first player wins, he plays until he gets eliminated.
                Players[j] = 0;
            }
            
            if (result == 2) { // If the second player wins, in the next turn he will try to go on the streak and try to win.
                Players[i] = 0;
                stop = true;
                i -= Winstreak;
            }
            Winstreak++; // The first player also gets a win streak so we know how many players we skip
        }

        for (int k = Players.size() - 1; k >= 0; k--) { // Erasing all the players that the first one has eliminated.
            if (Players[k] == 0)    
                Players.erase(Players.begin() + k);
        }       
    }
    
    WINNER:
    cout << endl;
    cout << "WINNER IS " << Competitors.getCompetitorName(Players[0]);
}

int showDuelGenken(string name1, string name2) // Returns 1 if the first player wins, returns 2 if the second player wins 
{
    int choice1 = rand() % 3;
    int choice2 = rand() % 3;

    while (choice1 == choice2) {
        choice1 = rand() % 3;
        choice2 = rand() % 3;
    }

    cout << name1 << leaveSpace(name1) << "VS   " << name2 << endl;
    cout << name1 << " chose " << Choice[choice1] << ". " << name2 << " chose " << Choice[choice2] << ". ";


    // ROCK = 0 , PAPER = 1, SCISSORS = 2 

    if (choice1 == 0 && choice2 == 1) {
        cout << name2 << " wins." << endl;
        return 2;
    }
    if (choice1 == 0 && choice2 == 2) {
        cout << name1 << " wins." << endl;
        return 1;
    }
    if (choice1 == 1 && choice2 == 0) {
        cout << name1 << " wins." << endl;
        return 1;
    }
    if (choice1 == 1 && choice2 == 2) {
        cout << name2 << " wins." << endl;
        return 2;
    }
    if (choice1 == 2 && choice2 == 0) {
        cout << name2 << " wins." << endl;
        return 2;
    }
    if (choice1 == 2 && choice2 == 1) {
        cout << name1 << " wins." << endl;
        return 1;
    }
    return 0;
}