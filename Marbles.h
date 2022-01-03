#include <iostream>

using namespace std;

string leaveSpaceDuel(string name); 
void showDuel(string name1, string name2);

void Marbles()
{
    vector <int> EliminatedPlayers;
    int n = Players.size();
    for (int i = 0; i < n / 2; i++) {
        // cout << Players[i] << " " << Players[n / 2 + i] << endl;
        string FirstPlayer = Competitors.getCompetitorName(Players[i]);
        string SecondPlayer = Competitors.getCompetitorName(Players[n / 2 + i]);
        showDuel(FirstPlayer, SecondPlayer);
    }


}

void showDuel(string name1, string name2)
{
    cout << name1 << leaveSpaceDuel(name1) << "VS   " << name2 << endl;
}

string leaveSpaceDuel(string name) 
{
    int x = 18 - name.size();
    string y;
    for (int i = 0; i < x; i++) {
        y = y + " ";
    }
    return y;
}