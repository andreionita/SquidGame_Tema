#include <vector>

vector <int> Players;

void RedLightGreenLight() 
{
    for (int i = 0; i < Players.size() - 1; i++) {
        if (Players[i] % 2 != 0) {
            Players.erase(Players.begin() + i);
            Competitors.eliminateCompetitor(Players[i]);
        }
    }
}