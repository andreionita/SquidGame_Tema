#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

string leaveSpaceDuel(string name); 
void showDuel(string name1, string name2, int nr1, int nr2);

void Marbles()
{
    int n = Players.size();

    srand(time(NULL));

    for (int i = 0; i < n / 2; i++) {
        // cout << Players[i] << " " << Players[n / 2 + i] << endl;
        string FirstPlayer = Competitors.getCompetitorName(Players[i]);
        string SecondPlayer = Competitors.getCompetitorName(Players[n / 2 + i]);
        int FirstPlayerRoll = rand() % 15 + 1;
        int SecondPlayerRoll = rand() % 15 + 1;

        while (FirstPlayerRoll == SecondPlayerRoll) {
            FirstPlayerRoll = rand() % 15 + 1;
            SecondPlayerRoll = rand() % 15 + 1;
        }

        if (FirstPlayerRoll < SecondPlayerRoll) {
            Players[i] = 0;
            cout << i << endl;
            Competitors.eliminateCompetitor(Players[i]);
        } else {
            cout << n / 2 + i << endl;
            Players[n / 2 + i] = 0;
            Competitors.eliminateCompetitor(Players[n / 2 + i]);
        }

        showDuel(FirstPlayer, SecondPlayer, FirstPlayerRoll, SecondPlayerRoll);
    }

    Competitors.showCompetitors();

    for (int i = Players.size() - 1; i >= 0; i--) {
        if (Players[i] == 0) 
            Players.erase(Players.begin() + i);
    }

    for (int i = 0; i < Players.size(); i++) {
        cout << Players[i] << " ";
    }
}

void showDuel(string name1, string name2, int nr1, int nr2)
{
    cout << name1 << leaveSpaceDuel(name1) << "VS   " << name2 << endl;
    cout << name1 << " rolled " << nr1 << ". " << name2 << " rolled " << nr2 << ". ";
    if (nr1 < nr2) {
        cout << name1 << " gets eliminated." << endl;
    } else {
        cout << name2 << " gets eliminated." << endl;
    }
    cout << endl;
}

string leaveSpaceDuel(string name) 
{
    int x = 20 - name.size();
    string y;
    for (int i = 0; i < x; i++) {
        y = y + " ";
    }
    return y;
}