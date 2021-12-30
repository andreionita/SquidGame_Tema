#include "CreateGame.h"
#include "RedLightGreenLight.h"

using namespace std;

int main()
{
    for (int i = 1; i < 100; i++) {
        Players.push_back(i);
    }

    createGame();
    RedLightGreenLight();

    Competitors.showCompetitors();

    return 0;
}