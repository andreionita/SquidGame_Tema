#include "GameData.h"
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

// Main classes initialization

CompetitorList Competitors;
SupervisorDivision Divisions[3];

// The "Players" vector will contain only the numbers of the players.
// When someone is eliminated, we erase their number from the vector.

vector <int> Players;

void createGame()
{
    // Reading data from the CSV file

    vector<string> index;
    vector<string> names;
    vector<string> surnames;
    vector<string> cities;

    string line, word;

    fstream file("Names_v2.csv", ios::in);

    getline(file, line); // Skipping the first line

    if (file.is_open()) {
        while (getline(file, line)) {

            stringstream str(line);

            getline(str, word, ',');
            index.push_back(word);

            getline(str, word, ',');
            names.push_back(word);

            getline(str, word, ',');
            surnames.push_back(word);

            getline(str, word, ',');
            cities.push_back(word);
        }
    }

    srand(time(NULL)); // Random game every time

    // Randomly assigning each person a number. Adding 99 players to the "Competitors" object. 

    int NumberAvailable = 108;
    for (int i = 0; i < 99; i++) {
        int PlayerNumber = rand() % NumberAvailable;

        Competitors.addPerson(names[PlayerNumber], surnames[PlayerNumber], cities[PlayerNumber]);

        names.erase(names.begin() + PlayerNumber);
        surnames.erase(surnames.begin() + PlayerNumber);
        cities.erase(cities.begin() + PlayerNumber);
        
        NumberAvailable--;
    }

    int supervisorIndex = 0;
    string maskType[] = {"Circle", "Triangle", "Square"};

    // The remaining 9 players that didn't get selected to be competitors for the big prize are now supervisors.
    // There will be 3 divisions. In each division, there will be each supervisor will have a different mask type (circle, triangle, square).

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++, supervisorIndex++) {
            Divisions[i].addPerson(names[supervisorIndex], surnames[supervisorIndex], cities[supervisorIndex], maskType[j]);
            index.pop_back();
        }
    }

    NumberAvailable = 99;

    // The competitors will have to be assigned to a supervisor. Since there are 99 players, each division will get 33 players.

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 33; j++) {
            int PlayerAssigned = rand() % NumberAvailable;
            Divisions[i].addCompetitor(stoi(index[PlayerAssigned]));
            index.erase(index.begin() + PlayerAssigned);
            NumberAvailable--;
        }
    }

    // The next split, in which each supervisor gets 11 players.

    for (int i = 0; i < NR_OF_DIVISIONS; i++) {
        Divisions[i].splitCompetitorsToSupervisors();
    }

    return;
}

