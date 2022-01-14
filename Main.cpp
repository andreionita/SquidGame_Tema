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
    for (int i = 1; i < 100; i++) {
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

    sort(Players.begin(), Players.end());

    cout << endl;

    Marbles();

    Genken();

    cout << endl;
    cout << Competitors.getBigPrize() << endl;


    WinnersEarnings();

    return 0;
}