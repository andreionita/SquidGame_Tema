#include "CreateGame.h"
#include "TugOfWar.h"
#include "RedLightGreenLight.h"
#include "Marbles.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int i = 1; i < 100; i++) {
        Players.push_back(i);
    }

    createGame();

    Competitors.showCompetitors();

    RedLightGreenLight();

    TugOfWar();

    sort(Players.begin(), Players.end());

    for (int i = 0; i < Players.size(); i++) {
        cout << Players[i] << " ";
    }
    cout << endl;

    Marbles();

    return 0;
}