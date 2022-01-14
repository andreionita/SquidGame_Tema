#include <bits/stdc++.h>

using namespace std;

struct Winner {
    string FullName;
    int PrizeWon;
};

bool comparator(Winner w1, Winner w2) {
    return (w1.PrizeWon > w2.PrizeWon);
}

void WinnersEarnings()
{
    vector <Winner> Winners;

    cout << endl;
    cout << "Press any key to display how much each player won... " << endl;
    _getch();

    cout << "\nHere is how much the winners of the competition have earned : \n";

    Winner w;
    w.FullName = Competitors.getCompetitorName(Players[0]);
    w.PrizeWon = Competitors.getBigPrize();

    Winners.push_back(w);

    for (int i = 0; i < NR_OF_DIVISIONS; i++) {
        for (int j = 0; j < 3; j++) {
            w.FullName = Divisions[i].getFullNameByIndex(j);
            w.PrizeWon = Divisions[i].getPrizeWonByIndex(Competitors, Players[0], j);

            Winners.push_back(w);
        }
    }

    sort(Winners.begin(), Winners.end(), comparator);

    for (auto x : Winners) {
        cout << x.FullName << " has won " << x.PrizeWon << ". \n";
        usleep(1000000);
    }
    
}