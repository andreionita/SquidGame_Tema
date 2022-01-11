#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

#define NR_OF_DIVISIONS 3

string leaveSpaceNames(string name, string city);

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

    string getFullName() {
        return this -> Name + " " + this -> Surname;
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
    bool isEliminated;
public:
    void setNumber(int number) {
        this -> Number = number;
        this -> isEliminated = false;
    }
    int getNumber() {
        return this -> Number;
    }

    void showDetails() {
        if (this -> Number < 10) {
                if (isEliminated) {
                return;
                cout << "ELIMINATED : " << getNumber() <<  ".  Name: " << getName() << " " << getSurname() << " from " <<
                    getCity() << leaveSpaceNames(getFullName(), getCity()) << " | Weight : " << getWeight() << " | Money owed : " << getMoneyOwed() << endl;  
            } else {
                cout << "     ALIVE : " << getNumber() <<  ".  Name: " << getName() << " " << getSurname() << " from " <<
                    getCity() << leaveSpaceNames(getFullName(), getCity()) << " | Weight : " << getWeight() << " | Money owed : " << getMoneyOwed() << endl;  
            }    
        } else {
                if (isEliminated) {
                return;
                cout << "ELIMINATED : " << getNumber() <<  ". Name: " << getName() << " " << getSurname() << " from " <<
                    getCity() << leaveSpaceNames(getFullName(), getCity()) << " | Weight : " << getWeight() << " | Money owed : " << getMoneyOwed() << endl;  
            } else {
                cout << "     ALIVE : " << getNumber() <<  ". Name: " << getName() << " " << getSurname() << " from " <<
                    getCity() << leaveSpaceNames(getFullName(), getCity()) << " | Weight : " << getWeight() << " | Money owed : " << getMoneyOwed() << endl;  
            }
        }
    }

    void getsEliminated() {
        this -> isEliminated = true;
    }
};

class People {
private:
    Competitor Person[102];
    int NOH; // Number of humans
public:
    People() {
        NOH = 1;
    }
    void addPerson(string name, string surname, string city) {
        Person[NOH].setName(name);
        Person[NOH].setSurname(surname);
        Person[NOH].setCity(city);
        Person[NOH].measureWeight();
        Person[NOH].writeMoneyOwed();
        Person[NOH].setNumber(NOH);
        NOH++;
    }

    int getWeightByIndex(int index) {
        return Person[index].getWeight();
    }

    void showNOH() {
        cout << NOH << endl;
    }
    void showCompetitors() {
        for (int i = 1; i < NOH; i++) {
            Person[i].showDetails();
        }
    }
    string getCompetitorName(int number) {
        return Person[number].getFullName();
    }

    void eliminateCompetitor(int number) {
        Person[number].getsEliminated();
    }

    int getMoneyOwedByIndex(int number) {
        return Person[number].getMoneyOwed();
    }

    int getBigPrize() {
        unsigned long int BigPrize = 0;
        for (int i = 1; i < NOH; i++) {
            BigPrize += getMoneyOwedByIndex(i);
        }

        return BigPrize;
    }
};

class Supervisor : public Human {
private:
    string Mask;
    vector <int> CompetitorsAllocated;
    unsigned long int PrizeWon;
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

    long int getPrize(People Competitors, int winnerNumber) {
        long int PrizeWon = 0;
        for (int i = 0; i < CompetitorsAllocated.size(); i++) {
            int PlayerNumber = CompetitorsAllocated[i];
            if (winnerNumber == PlayerNumber) {
                PrizeWon += Competitors.getMoneyOwedByIndex(PlayerNumber) * 10;
            } else {
                PrizeWon += Competitors.getMoneyOwedByIndex(PlayerNumber);
            }
        }
        PrizeWon -= getMoneyOwed();
        // cout << "Supervisor : " << getName() << " " << getSurname() << " has won " << PrizeWon << endl;
        return PrizeWon;
    }
};

class SupervisorDivision {
private:
    Supervisor Person[3];
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

    void showEarnings(People Competitors, int number) {
        for (int i = 0; i < NOS; i++) {
            Person[i].getPrize(Competitors, number);
        }
    }

    string getFullNameByIndex(int index) {
        return Person[index].getFullName();
    }

    long int getPrizeWonByIndex(People Competitors, int winnerNumber, int index) {
        return Person[index].getPrize(Competitors, winnerNumber);
    }
};

string leaveSpaceNames(string name, string city)
{
    int x = 40 - name.size() - city.size();
    string y;
    for (int i = 0; i < x; i++) {
        y = y + " ";
    }
    return y;
}

#endif