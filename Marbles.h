#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

string leaveSpaceDuel(string name); 
void showDuelMarbles(string name1, string name2, int nr1, int nr2);

void Marbles()
{
    cout << "Players now will duel using marbles. Each player throw their marbles and they have to roll lower than their opponent. \n";
    usleep(3000000);

    cout << "The player which has the lower number will advance to the next game. The other one will be eliminated.\n";
    usleep(3000000);

    cout << "\nPress any key to continue... " << endl;
    _getch();

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
            Competitors.eliminateCompetitor(Players[n / 2 + i]);
            Players[n / 2 + i] = 0;
        } else {
            Competitors.eliminateCompetitor(Players[i]);
            Players[i] = 0;
        }

        showDuelMarbles(FirstPlayer, SecondPlayer, FirstPlayerRoll, SecondPlayerRoll);
    }

    cout << "\nPress any key to show the remaining players... " << endl;
    _getch();

    Competitors.showCompetitors();

    for (int i = Players.size() - 1; i >= 0; i--) {
        if (Players[i] == 0) 
            Players.erase(Players.begin() + i);
    }

    cout << "\nPress any key to continue... " << endl;
    _getch();
}

void showDuelMarbles(string name1, string name2, int nr1, int nr2)
{
    usleep(1000000);
    cout << name1 << leaveSpaceDuel(name1) << "VS   " << name2 << endl;

    usleep(1000000);
    cout << name1 << " rolled " << nr1 << ". " << name2 << " rolled " << nr2 << ". ";
    if (nr1 > nr2) {
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