#include "GameController.hpp"

int main() {
    GameController gameController;

    gameController.initializePlayers();
    int error = gameController.initializePistols();

    if(error != 0) {
        return 1;
    }

    while (gameController.isGameActive()) {
        gameController.playRound();
    }

    return 0;
}
