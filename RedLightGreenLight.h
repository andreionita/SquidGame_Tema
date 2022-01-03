#include <vector>

vector <int> Players;

void RedLightGreenLight() 
{
    for (int i = 2; i < 100; i += 2) {
        Competitors.eliminateCompetitor(i);
    }
    for (int i = Players.size() - 2; i > 0; i -= 2) {
        Players.erase(Players.begin() + i);
    }

    cout << endl << "ALL PLAYERS WITH EVEN NUMBERS HAVE BEEN ELIMINATED !" << endl << endl;
    Competitors.showCompetitors();
}