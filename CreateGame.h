#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

class Human {
private:
    string Name;
    string Surname;
    string City;
    int MoneyOwed;
    int Weight;
public:
    Human() {
        MoneyOwed = 0;
        Weight = 0;
    }
    void setName(string name) {
        this -> Name = name;
    }
    void setSurname(string surname) {
        this -> Surname = surname;
    }
    void setCity(string city) {
        this -> City = city;
    }

    void measureWeight() {
        this -> Weight = rand() % 51 + 50;
    }
    void writeMoneyOwed() {
        this -> MoneyOwed = (rand() % 91) * 1000 + 10000; 
    }

    string getName() {
        return this -> Name;
    } 
    string getSurname() {
        return this -> Surname;
    }
    string getCity() {
        return this -> City;
    }

    int getWeight() {
        return this -> Weight;
    }

    int getMoneyOwed() {
        return this -> MoneyOwed;
    }
};

class Competitor : public Human {
private:
    int Number;
public:
    void setNumber(int number) {
        this -> Number = number;
    }
    int getNumber() {
        return this -> Number;
    }
    void showDetails() {
        cout << getNumber() <<  ". Name: " << getName() << " " << getSurname() << " from " << getCity() << " | Weight : " << getWeight() << " | Money owed : " << getMoneyOwed() << endl;  
    }
};

class Supervisor : public Human {
private:
    string Mask;
    vector <int> CompetitorsAllocated;
public:
    void setMask(string mask) {
        this -> Mask = mask;
    }

    string getMask() {
        return this -> Mask;
    }
    void showDetails() {
        cout << "Mask : " << getMask() <<  ". Name: " << getName() << " " << getSurname() << " from " << getCity() << " | Weight : " << getWeight() << " | Money owed : " << getMoneyOwed() << endl;  
    }

    void addCompetitors(int number) {
        CompetitorsAllocated.push_back(number);
    }

    void showAllocatedCompetitors() {
        cout << "Supervisor : " << getName() << " " << getSurname() << " has these competitors assigned : ";
        for (int i = 0; i < CompetitorsAllocated.size(); i++) {
            cout << CompetitorsAllocated[i] << " ";
        }
        cout << endl;
    }
};

class SupervisorDivision {
private:
    Supervisor Person[3];
    // vector <Supervisor> Person;
    int NOS; // Number of Supervisors
    vector <int> CompetitorsAssigned;
public:
    SupervisorDivision() {
        NOS = 0;
    }
    void addPerson(string name, string surname, string city, string mask) {
        Person[NOS].setName(name);
        Person[NOS].setSurname(surname);
        Person[NOS].setCity(city);
        Person[NOS].measureWeight();
        Person[NOS].writeMoneyOwed();
        Person[NOS].setMask(mask);
        NOS++;
    }

    void showDetails() {
        for (int i = 0; i < NOS; i++) {
            Person[i].showDetails();
        }
    }

    void addCompetitor(int number) {
        CompetitorsAssigned.push_back(number);
    }

    void deleteCompetitor(int number) {
        CompetitorsAssigned.erase(CompetitorsAssigned.begin() + number);
    }

    void showAssignedCompetitors() {
        for (int i = 0; i < CompetitorsAssigned.size(); i++) 
            cout << CompetitorsAssigned[i] << " ";
        cout << endl;
    }

    void splitCompetitorsToSupervisors() {
        try {
            if (CompetitorsAssigned.size() != 33)
                throw 1;
            for (int i = 0, x = 0; i < NOS; i++, x++) {
                for (int j = 0; j < 9; j++, x++) {
                    Person[i].addCompetitors(CompetitorsAssigned[x]);
                }
            }
        } catch (...) {
            cout << "Incorrect number of competitors assigned" << endl;
        }
    }
    void showSplit() {
        for (int i = 0; i < NOS; i++) {
            Person[i].showAllocatedCompetitors();
        }
    }
};

class People {
private:
    Competitor Person[100];
    int NOH; // Number of humans
public:
    People() {
        NOH = 0;
    }
    void addPerson(string name, string surname, string city) {
        Person[NOH].setName(name);
        Person[NOH].setSurname(surname);
        Person[NOH].setCity(city);
        Person[NOH].measureWeight();
        Person[NOH].writeMoneyOwed();
        Person[NOH].setNumber(NOH + 1);
        NOH++;
    }
    void showNOH() {
        cout << NOH << endl;
    }
    void showCompetitors() {
        for (int i = 0; i < NOH; i++) {
            Person[i].showDetails();
        }
    }
};

People Competitors;
SupervisorDivision Divisions[3];

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
    cout << "1";


    // Competitors.showCompetitors();

    // for (int i = 0; i < 3; i++) {
    //     Divisions[i].showDetails();
    // }

    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 33; j++) {
    //         // int PlayerAssigned = rand() % NumberAvailable;
    //         // cout << index[PlayerAssigned] << " ";
    //         // // PlayersAvailable.erase(PlayersAvailable.begin() + PlayerAssigned);
    //         // NumberAvailable--;
    //     }
    //     // cout << endl;
    // }

    NumberAvailable = 99;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 33; j++) {
            int PlayerAssigned = rand() % NumberAvailable;
            Divisions[i].addCompetitor(stoi(index[PlayerAssigned]));
            // cout << index[PlayerAssigned] << " ";
            index.erase(index.begin() + PlayerAssigned);
            NumberAvailable--;
        }
        // cout << endl;
    }

    Divisions[0].showAssignedCompetitors();
    Divisions[1].showAssignedCompetitors();
    Divisions[2].showAssignedCompetitors();


    Divisions[0].splitCompetitorsToSupervisors();
    Divisions[1].splitCompetitorsToSupervisors();
    Divisions[2].splitCompetitorsToSupervisors();


    Divisions[0].showSplit();
    Divisions[1].showSplit();
    Divisions[2].showSplit();



    return;
}

