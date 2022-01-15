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

    // Erasing the even numbered players because they can't be used in the other games.

    for (int i = Players.size() - 2; i > 0; i -= 2) {
        Players.erase(Players.begin() + i);
    }

    cout << "\nPress any key to show remaining players... " << endl;
    _getch();

    usleep(1000000);

    cout << endl << "All players with even number have been eliminated !" << endl;
    cout << "The following players remain : \n\n";

    usleep(2000000);

    Competitors.showCompetitors();

    cout << "\nPress any key to continue... " << endl;
    _getch();
}