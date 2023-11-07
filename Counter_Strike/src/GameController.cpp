#include "GameController.hpp"
#include "Defines.hpp"

GameController::GameController() : currentPlayerIndex(0), gameActive(true) {}

void GameController::initializePlayers() {
    int playersCount;
    std::cout << "Enter number of players: ";
    std::cin >> playersCount;

    players.reserve(playersCount);
    for (int i = 0; i < playersCount; ++i) {
        int initialHealth, initialArmor;
        std::cout << Messages::PLAYER_INPUT << i << ": ";
        std::cin >> initialHealth >> initialArmor;
        players.emplace_back(initialHealth, initialArmor);
    }
}

int GameController::initializePistols() {
    for (Player& player : players) {
        int pistolId, pistolDamage, pistolClipSize, pistolAmmo;
        int index = &player - &players[0];
        std::cout << Messages::PISTOL_INPUT << index << ": ";
        std::cin >> pistolId >> pistolDamage >> pistolClipSize >> pistolAmmo;
        int errorCall = player.buyPistol(static_cast<PistolType>(pistolId), pistolDamage, pistolClipSize, pistolAmmo);

        if(errorCall != 0) {
            return 1;
        }
    }
}

void GameController::playRound() {
    Player& currentPlayer = players[currentPlayerIndex];

    if (currentPlayer.isAlive()) {
        std::cout << Messages::PLAYER_ID << currentPlayerIndex << Messages::TURN;

        for (Player& target : players) {
            if (&target != &currentPlayer && target.isAlive()) {
                target.takeDamage(currentPlayer.shoot());

                std::cout << Messages::NEW_LINE;

                if (!target.isAlive()) {
                    std::cout << Messages::PLAYER_WITH_ID << currentPlayerIndex << Messages::WIN;
                    gameActive = false;

                    /*int counter = 0;
                    for(Player& player : players) {
                        if(player.isAlive()) {
                            ++counter;
                        }
                    }
                    if(counter == 1) {
                        gameActive = false;
                    }*/
                    return;
                }
            }
        }
    }

    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
}

bool GameController::isGameActive() const {
    return gameActive;
}
