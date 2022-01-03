#include "GameData.h"
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

People Competitors;
SupervisorDivision Divisions[3];
vector <int> Players;

void createGame()
{
    vector<string> index;
    vector<string> names;
    vector<string> surnames;
    vector<string> cities;

    string line, word;

    fstream file("Names_v2.csv", ios::in);

    getline(file, line);

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

    srand(time(NULL));

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

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++, supervisorIndex++) {
            Divisions[i].addPerson(names[supervisorIndex], surnames[supervisorIndex], cities[supervisorIndex], maskType[j]);
            index.pop_back();
        }
    }

    NumberAvailable = 99;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 33; j++) {
            int PlayerAssigned = rand() % NumberAvailable;
            Divisions[i].addCompetitor(stoi(index[PlayerAssigned]));
            index.erase(index.begin() + PlayerAssigned);
            NumberAvailable--;
        }
    }

    for (int i = 0; i < NR_OF_DIVISIONS; i++) {
        Divisions[i].splitCompetitorsToSupervisors();
    }

    return;
}

