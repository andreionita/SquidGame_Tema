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
public:
    void setName(string name) {
        this -> Name = name;
    }
    void setSurname(string surname) {
        this -> Surname = surname;
    }

    string getName() {
        return this -> Name;
    } 
    string getSurname() {
        return this -> Surname;
    }

    void showName() {
        cout << "Name: " << getName() << " " << getSurname() << endl;
    }
};

class People {
private:
    Human Person[105];
    int NOH; // Number of humans
public:
    People() {
        NOH = 0;
    }
    void addPerson(string name, string surname) {
        Person[NOH].setName(name);
        Person[NOH].setSurname(surname);
        NOH++;
    }
    void showNOH() {
        cout << NOH << endl;
    }
    void showPeople() {
        for (int i = 0; i < NOH; i++) {
            Person[i].showName();
        }
    }
};

int main()
{
    People Competitors;
    vector<string> index;
    vector<string> names;
    vector<string> surnames;

    string line, word;

    fstream file("Names.csv", ios::in);

    if (file.is_open()) {
        while (getline(file, line)) {

            stringstream str(line);

            getline(str, word, ',');
            index.push_back(word);

            getline(str, word, ',');
            names.push_back(word);

            getline(str, word, ',');
            surnames.push_back(word);
        }
    }

    srand(time(NULL));

    int NumberAvailable = 100;
    for (int i = 0; i < index.size(); i++) {

        int NameIndex = rand() % NumberAvailable;
        int SurnameIndex = rand() % NumberAvailable;

        Competitors.addPerson(names[NameIndex], surnames[SurnameIndex]);

        names.erase(names.begin() + NameIndex);
        surnames.erase(surnames.begin() + SurnameIndex);

        NumberAvailable--;
    }

    Competitors.showPeople();

    return 0;
}