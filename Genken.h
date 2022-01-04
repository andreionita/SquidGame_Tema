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

    srand(time(NULL));

    int Rounds = 1;

    while(Players.size() > 1) {
        cout << endl << "ROUND " << Rounds << endl;
        for (int i = Players.size() - 2; i >= 0; i -= 2) {
        // cout << Players[i] << " " << Players[i + 1] << endl;
        string FirstPlayer  = Competitors.getCompetitorName(Players[i]);
        string SecondPlayer = Competitors.getCompetitorName(Players[i + 1]);

        int result = showDuelGenken(FirstPlayer, SecondPlayer); 

        if (result == 1) {
            Players[i + 1] = 0;
        }
        if (result == 2) {
            Players[i] = 0;
        }

        for (int j = Players.size() - 1; j >= 0; j--) 
            if (Players[j] == 0) 
                Players.erase(Players.begin() + j);
        }
        for (int j = 0; j < Players.size(); j++)
            cout << Players[j] << " ";
        cout << endl;
        Rounds++;
    }
    
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