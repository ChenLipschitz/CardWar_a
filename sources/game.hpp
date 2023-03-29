#pragma once
#include <iostream>
#include "player.hpp"

namespace ariel{
    class Game{
        private:
        Player player1;
        Player player2;
        string winersName;
        int numOfDraws;
        
        public:
        Game(Player player1, Player player2);    
        void playTurn();
        void printLastTurn();
        void printWiner();
        void printLog();
        void printStats();
        void playAll();
        int getNumOfDraws();
    };
}
