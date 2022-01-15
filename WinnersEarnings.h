#include <bits/stdc++.h>

using namespace std;

struct Winner {
    string FullName;
    int PrizeWon;
};

struct TeamEarnings {
    int DivisionNumber;
    int PrizeWon;
};

bool comparator1(Winner w1, Winner w2) { // To sort by prize and in descending order
    return (w1.PrizeWon > w2.PrizeWon);
}

bool comparator2(TeamEarnings t1, TeamEarnings t2) { // To sort by prize and in descending order
    return (t1.PrizeWon > t2.PrizeWon);
}

void WinnersEarnings()
{
    vector <Winner> Winners; // Contains only the name and winnings of the supervisors and the winner of the game
    vector <TeamEarnings> Team;

    cout << endl;
    cout << "Press any key to display how much each player won... " << endl;
    _getch();

    cout << "\nHere is how much the winners of the competition have earned : \n";

    Winner w;
    TeamEarnings T;

    // Getting the name and the big prize of the winner

    w.FullName = Competitors.getCompetitorName(Players[0]); 
    w.PrizeWon = Competitors.getBigPrize();

    Winners.push_back(w);

    // Getting the names and winnings for the supervisors.

    for (int i = 0; i < NR_OF_DIVISIONS; i++) {
        T.DivisionNumber = i + 1;
        T.PrizeWon = 0;

        for (int j = 0; j < 3; j++) {
            w.FullName = Divisions[i].getFullNameByIndex(j);
            w.PrizeWon = Divisions[i].getPrizeWonByIndex(Competitors, Players[0], j);

            T.PrizeWon += w.PrizeWon;

            Winners.push_back(w);
        }
        Team.push_back(T);
    }

    sort(Winners.begin(), Winners.end(), comparator1);
    sort(Team.begin(), Team.end(), comparator2);

    for (auto x : Winners) {
        cout << x.FullName << " has won " << x.PrizeWon << ". \n";
        usleep(1000000);
    }

    cout << "\nThe supervisor team that won the most money is Team " << Team[0].DivisionNumber << " with " << Team[0].PrizeWon << endl;
}