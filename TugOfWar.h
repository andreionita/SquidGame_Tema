#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <bits/stdc++.h>

using namespace std;

// After the first game, there will only be 50 players. Since the rest of the players will be divided in 4 teams, 
// there will be 4 teams, each with 12 members.

#define NR_OF_TEAMS 4
#define PLAYERS_PER_TEAM 12

vector<vector<int>> Teams( NR_OF_TEAMS , vector<int> (PLAYERS_PER_TEAM)); // 

string leaveSpace(string name);
void showTugOfWarTeams(string name1, string name2);

void TugOfWar()
{
    cout << "The next game will be tug of war. In this game, the weight of each person will play an important role in winning. \n";
    usleep(3000000);
    cout << "The team that outweighs the other will win and will advance to the next game. The losing team will be eliminated. \n";
    usleep(3000000);
    cout << "Press any key to start the game Tug of War\n";
    _getch();

    int NumberAvailable = Players.size();

    // Randomly assigning each player to a team. We erase them from the "Players" vector.
    // The 2 players that didn't get assigned will advance to the next game.

    for (int i = 0; i < NR_OF_TEAMS; i++) {
        for (int j = 0; j < PLAYERS_PER_TEAM; j++) {
            int PlayerNumber = rand() % NumberAvailable; 
            Teams[i][j] = Players[PlayerNumber];
            Players.erase(Players.begin() + PlayerNumber);
            NumberAvailable--;
        }
    }

    cout << endl;

    int Team1Weight = 0;
    int Team2Weight = 0;
    int Team3Weight = 0;
    int Team4Weight = 0;


    cout << "FIRST ROUND : \n";
    usleep(1000000);

    cout << "TEAM 1" << leaveSpace("TEAM 1") << "VS     TEAM 3" << endl;
    usleep(1000000);

    for (int i = 0; i < PLAYERS_PER_TEAM; i++) {

        // Getting the data that is relevant for the game of tug of war: name and weight.

        int Team1PersonWeight = Competitors.getWeightByIndex(Teams[0][i]);
        int Team3PersonWeight = Competitors.getWeightByIndex(Teams[2][i]);
        string Team1PersonName = Competitors.getCompetitorName(Teams[0][i]);
        string Team3PersonName = Competitors.getCompetitorName(Teams[2][i]);

        showTugOfWarTeams(Team1PersonName, Team3PersonName);
        usleep(100000);

        Team1Weight += Team1PersonWeight;
        Team3Weight += Team3PersonWeight;
    }

    usleep(1000000);

    cout << "TEAM 1 Weight : " << Team1Weight << leaveSpace("TEAM 1 Weight : 999") << "VS     TEAM 3 Weight : " << Team3Weight << endl;
    cout << endl;

    usleep(1000000);

    // Team with the lower total weight will be eliminated.
    // Since the "Players" vector contains only 2 competitors,
    // the winners of this game will be added back to the vector and continue playing.

    if (Team1Weight > Team3Weight) { 
        cout << "TEAM 3 gets eliminated : \n";
        usleep(2000000);
        for (int i = 0; i < PLAYERS_PER_TEAM; i++) {

            Competitors.eliminateCompetitor(Teams[2][i]);
            Players.push_back(Teams[0][i]);

            cout << "Eliminated number " << Teams[2][i] << ": " << Competitors.getCompetitorName(Teams[2][i]) << ".\n";
            usleep(100000);
        }
    } else {
        cout << "TEAM 1 gets eliminated : \n";
        usleep(2000000);
        for (int i = 0; i < PLAYERS_PER_TEAM; i++) {

            Competitors.eliminateCompetitor(Teams[0][i]);
            Players.push_back(Teams[2][i]);

            cout << "Eliminated number " << Teams[0][i] << ": " << Competitors.getCompetitorName(Teams[0][i]) << ".\n";
            usleep(100000);
        }
    
    }

    cout << "\nPress any key to continue... " << endl;
    _getch();

    // Same procces with the other 2 teams.

    usleep(1000000);
    cout << "TEAM 2" << leaveSpace("TEAM 2") << "VS     TEAM 4" << endl << endl;
    usleep(1000000);

    for (int i = 0; i < PLAYERS_PER_TEAM; i++) {
        int Team2PersonWeight = Competitors.getWeightByIndex(Teams[1][i]);
        int Team4PersonWeight = Competitors.getWeightByIndex(Teams[3][i]);
        string Team2PersonName = Competitors.getCompetitorName(Teams[1][i]);
        string Team4PersonName = Competitors.getCompetitorName(Teams[3][i]);
        
        showTugOfWarTeams(Team2PersonName, Team4PersonName);
        usleep(100000);

        Team2Weight += Team2PersonWeight;
        Team4Weight += Team4PersonWeight;
    }

    cout << "TEAM 2 Weight : " << Team2Weight << leaveSpace("TEAM 2 Weight : 999") << "VS     TEAM 4 Weight : " << Team4Weight << endl;
    cout << endl;

    usleep(1000000);

    if (Team2Weight > Team4Weight) {
        cout << "TEAM 4 gets eliminated : \n";
        usleep(2000000);
        for (int i = 0; i < PLAYERS_PER_TEAM; i++) {

            Competitors.eliminateCompetitor(Teams[3][i]);
            Players.push_back(Teams[1][i]);

            cout << "Eliminated number " << Teams[3][i] << ": " << Competitors.getCompetitorName(Teams[3][i]) << ".\n";
            usleep(100000);
        }
    } else {
        cout << "TEAM 2 gets eliminated : \n";
        usleep(2000000);
        for (int i = 0; i < PLAYERS_PER_TEAM; i++) {

            Competitors.eliminateCompetitor(Teams[1][i]);
            Players.push_back(Teams[3][i]);

            cout << "Eliminated number " << Teams[1][i] << ": " << Competitors.getCompetitorName(Teams[1][i]) << ".\n";
            usleep(100000);
        }
    }

    sort(Players.begin(), Players.end());

    cout << "\nPress any key to show remaining players... " << endl;
    _getch();

    Competitors.showCompetitors();

    cout << "\nPress any key to continue to the next game... " << endl;
    _getch();
}

string leaveSpace(string name) 
{
    int x = 24 - name.size();
    string y;
    for (int i = 0; i < x; i++) {
        y = y + " ";
    }
    return y;
}

void showTugOfWarTeams(string name1, string name2)
{
    cout << name1 << leaveSpace(name1)
             << "VS     "  << name2 << endl;
}