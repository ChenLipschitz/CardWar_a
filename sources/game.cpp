
#include "player.hpp"
#include "game.hpp"
using namespace ariel;

Game::Game(Player player1_, Player player2_){
    this->player1 = player1_;
    this->player2 = player2_;
}

void Game::printWiner(){};
void Game::printStats(){};
void Game::printLog(){};
void Game::printLastTurn(){};
void Game::playTurn(){};
void Game::playAll(){};

