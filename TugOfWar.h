#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "RedLightGreenLight.h"

using namespace std;

#define NR_OF_TEAMS 4
#define PLAYERS_PER_TEAM 12

vector<vector<int>> Teams( NR_OF_TEAMS , vector<int> (PLAYERS_PER_TEAM));

string leaveSpace(string name);

void TugOfWar()
{
    int NumberAvailable = Players.size();

    for (int i = 0; i < NR_OF_TEAMS; i++) {
        for (int j = 0; j < PLAYERS_PER_TEAM; j++) {
            int PlayerNumber = rand() % NumberAvailable; 
            Teams[i][j] = Players[PlayerNumber];
            Players.erase(Players.begin() + PlayerNumber);
            NumberAvailable--;
        }
    }

    for (int i = 0; i < NR_OF_TEAMS; i++) {
        for (int j = 0; j < PLAYERS_PER_TEAM; j++) {
            cout << Teams[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < Players.size(); i++) {
        cout << Players[i] << " ";
    }

    cout << endl;

    int Team1Weight = 0;
    int Team2Weight = 0;
    int Team3Weight = 0;
    int Team4Weight = 0;

    cout << "TEAM 1" << leaveSpace("x") << "VS     TEAM 3" << endl;
    cout << endl;

    for (int i = 0; i < PLAYERS_PER_TEAM; i++) {
        int Team1PersonWeight = Competitors.getWeightByIndex(Teams[0][i]);
        int Team3PersonWeight = Competitors.getWeightByIndex(Teams[2][i]);
        string Team1PersonName = Competitors.getCompetitorName(Teams[0][i]);
        string Team3PersonName = Competitors.getCompetitorName(Teams[2][i]);
        cout << Team1PersonName << " with " << Team1PersonWeight << " kg." << leaveSpace(Team1PersonName)
             << "VS     "  << Team3PersonName << " with " << Team3PersonWeight << " kg." << endl;
        Team1Weight += Team1PersonWeight;
        Team3Weight += Team3PersonWeight;
    }
    cout << "TEAM 1 Weight : " << Team1Weight << leaveSpace("TEAM 1 Weight ") << " VS TEAM 3 Weight : " << Team3Weight << endl;
    cout << endl;

    if (Team1Weight > Team3Weight) {
        for (int i = 0; i < PLAYERS_PER_TEAM; i++) {
            Competitors.eliminateCompetitor(Teams[2][i]);
            Players.push_back(Teams[0][i]);
        }
    } else {
        for (int i = 0; i < PLAYERS_PER_TEAM; i++) {
            Competitors.eliminateCompetitor(Teams[0][i]);
            Players.push_back(Teams[2][i]);
        }
    
    }
    cout << "TEAM 2" << leaveSpace("x") << "VS     TEAM 4" << endl << endl;

    for (int i = 0; i < PLAYERS_PER_TEAM; i++) {
        int Team2PersonWeight = Competitors.getWeightByIndex(Teams[1][i]);
        int Team4PersonWeight = Competitors.getWeightByIndex(Teams[3][i]);
        string Team2PersonName = Competitors.getCompetitorName(Teams[1][i]);
        string Team4PersonName = Competitors.getCompetitorName(Teams[3][i]);
        cout << Team2PersonName << " with " << Team2PersonWeight << " kg." << leaveSpace(Team2PersonName)
             << "VS     "  << Team4PersonName << " with " << Team4PersonWeight << " kg." << endl;
        Team2Weight += Team2PersonWeight;
        Team4Weight += Team4PersonWeight;
    }
    cout << "TEAM 2 Weight : " << Team2Weight << leaveSpace("TEAM 1 Weight ") << " VS TEAM 4 Weight : " << Team4Weight << endl;
    if (Team2Weight > Team4Weight) {
        for (int i = 0; i < PLAYERS_PER_TEAM; i++) {
            Competitors.eliminateCompetitor(Teams[3][i]);
            Players.push_back(Teams[1][i]);
        }
    } else {
        for (int i = 0; i < PLAYERS_PER_TEAM; i++) {
            Competitors.eliminateCompetitor(Teams[1][i]);
            Players.push_back(Teams[3][i]);
        }
    }
}

string leaveSpace(string name) 
{
    int x = 20 - name.size();
    string y;
    for (int i = 0; i < x; i++) {
        y = y + " ";
    }
    return y;
}
