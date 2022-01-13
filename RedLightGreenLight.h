#include <vector>
#include <conio.h>
#include <unistd.h>

void RedLightGreenLight() 
{
    cout << "First game will be Red Light Green Light " << endl;
    cout << "Press any key to start the game... " << endl;
    _getch();

    cout << endl;
    for (int i = 2; i < 100; i += 2) {
        Competitors.eliminateCompetitor(i);
        cout << "Eliminated number " << i << ": " << Competitors.getCompetitorName(i) << ".\n";
        usleep(100000);
    }

    for (int i = Players.size() - 2; i > 0; i -= 2) {
        Players.erase(Players.begin() + i);
    }

    cout << "\nPress any key to show remaining players... " << endl;
    _getch();

    cout << endl << "ALL PLAYERS WITH EVEN NUMBERS HAVE BEEN ELIMINATED !" << endl;
    cout << "THE FOLLOWING PLAYERS REMAIN : \n\n";

    Competitors.showCompetitors();

    cout << "\nPress any key to continue... " << endl;
    _getch();
}