#include "CreateGame.h"
#include "RedLightGreenLight.h"
#include "TugOfWar.h"
#include "Marbles.h"
#include "Genken.h"
#include "WinnersEarnings.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int i = 1; i < 100; i++) { // Containts numbers from 1 to 99.
        Players.push_back(i);
    }

    createGame();

    Competitors.showCompetitors();
    usleep(1000000);

    for (int i = 0; i < NR_OF_DIVISIONS; i++) {
        cout << endl;
        cout << "DIVISION " << i + 1 << endl;
        Divisions[i].showDetails();
        usleep(1000000);
    }

    cout << endl;

    RedLightGreenLight();

    TugOfWar();

    Marbles();

    Genken();

    WinnersEarnings();

    return 0;
}