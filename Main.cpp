#include "CreateGame.h"
#include "TugOfWar.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int i = 1; i < 100; i++) {
        Players.push_back(i);
    }

    createGame();
    RedLightGreenLight();

    TugOfWar();

    Competitors.showCompetitors();

    sort(Players.begin(), Players.end());

    for (int i = 0; i < Players.size(); i++) {
        cout << Players[i] << " ";
    }

    return 0;
}