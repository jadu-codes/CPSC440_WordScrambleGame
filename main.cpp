#include <iostream>
#include "logic.h"

using namespace std;

int main() {
    logic game;

    game.introduction();

    if (!game.createLists()) {
        cout << "The game could not start because dictionary.txt is missing or does not have enough words.\n";
        return 1;
    }

    game.playGame();
    game.end();

    return 0;
}