#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <time.h>

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
};

class SupervisorDivision {
private:
    Supervisor Person[3];
    int NOS; // Number of Supervisors
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

int main()
{
    People Competitors;
    SupervisorDivision Division1, Division2, Division3;

    vector<string> index;
    vector<string> names;
    vector<string> surnames;
    vector<string> cities;

    string line, word;

    fstream file("Names_v2.csv", ios::in);

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

    Division1.addPerson(names[supervisorIndex], surnames[supervisorIndex], cities[supervisorIndex], maskType[0]);
    supervisorIndex++;
    Division1.addPerson(names[supervisorIndex], surnames[supervisorIndex], cities[supervisorIndex], maskType[1]);
    supervisorIndex++;
    Division1.addPerson(names[supervisorIndex], surnames[supervisorIndex], cities[supervisorIndex], maskType[2]);
    supervisorIndex++;

    Division2.addPerson(names[supervisorIndex], surnames[supervisorIndex], cities[supervisorIndex], maskType[0]);
    supervisorIndex++;
    Division2.addPerson(names[supervisorIndex], surnames[supervisorIndex], cities[supervisorIndex], maskType[1]);
    supervisorIndex++;
    Division2.addPerson(names[supervisorIndex], surnames[supervisorIndex], cities[supervisorIndex], maskType[2]);
    supervisorIndex++;

    Division3.addPerson(names[supervisorIndex], surnames[supervisorIndex], cities[supervisorIndex], maskType[0]);
    supervisorIndex++;
    Division3.addPerson(names[supervisorIndex], surnames[supervisorIndex], cities[supervisorIndex], maskType[1]);
    supervisorIndex++;
    Division3.addPerson(names[supervisorIndex], surnames[supervisorIndex], cities[supervisorIndex], maskType[2]);
    supervisorIndex++;

    Competitors.showCompetitors();

    Division1.showDetails();
    Division2.showDetails();
    Division3.showDetails();

    return 0;
}