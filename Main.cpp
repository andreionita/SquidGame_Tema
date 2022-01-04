#include "CreateGame.h"
#include "RedLightGreenLight.h"
#include "TugOfWar.h"
#include "Marbles.h"
#include "Genken.h"
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

    Genken();

    return 0;
}