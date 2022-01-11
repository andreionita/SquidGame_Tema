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

    RedLightGreenLight();

    TugOfWar();

    sort(Players.begin(), Players.end());

    for (int i = 0; i < Players.size(); i++) {
        cout << Players[i] << " ";
    }
    cout << endl;

    Marbles();

    Genken();

    cout << endl;
    cout << Competitors.getBigPrize() << endl;

    // for (int i = 0; i < NR_OF_DIVISIONS; i++) {
    //     Divisions[i].showDetails();
    //     Divisions[i].showSplit();
    //     Divisions[i].showEarnings(Competitors, Players[0]);
    // }

    WinnersEarnings();

    return 0;
}