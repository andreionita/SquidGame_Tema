#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Winners {
private:
    string FullName;
    unsigned long int PrizeWon;
public:
    Winners() {
        PrizeWon = 0;
    }

    void setName(string fullName) {
        this -> FullName = fullName;
    }

    void setPrizeWon(unsigned long int prize) {
        this -> PrizeWon = prize;
    } 

    string getFullName() {
        return this -> FullName;
    }

    long int getPrizeWon() {
        return this -> PrizeWon;
    }
};

void WinnersEarnings()
{
    
}