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
        for (int i = Players.size() - 1; i > 0; i--) {
        // cout << Players[i] << " " << Players[i + 1] << endl;
            string FirstPlayer  = Competitors.getCompetitorName(Players[i]);
            bool stop = false;
            for (int j = i - 1, z = 0; j >= 0 && stop == false; j--) {
                string SecondPlayer = Competitors.getCompetitorName(Players[j]);
                int result = showDuelGenken(FirstPlayer, SecondPlayer);
                cout << result << endl;
                for (int k = 0; k < Players.size(); k++)
                    cout << Players[k] << " ";
                cout << endl;
                if (result == 1) 
                    Players[j] = 0;
                
                if (result == 2) {
                    Players[i] = 0;
                    stop = true;
                    i-=z;
                }
                z++;
            }

            for (int k = Players.size() - 1; k >= 0; k--) 
                if (Players[k] == 0) 
                    Players.erase(Players.begin() + k);
        }

        for (int k = 0; k < Players.size(); k++)
            cout << Players[k] << " ";
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