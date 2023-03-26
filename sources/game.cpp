#include "game.hpp";
#include "player.hpp";
using namespace ariel;

Game::Game(Player p1_, Player p2_){
    this->p1 = p1_;
    this->p2 = p2_;
}

void Game::printWiner(){};
void Game::printStats(){};
void Game::printLog(){};
void Game::printLastTurn(){};
void Game::playTurn(){};
void Game::playAll(){};
