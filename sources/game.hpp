#pragma once
#include <iostream>;

namespace ariel{
    class Game{
        public:
            Game(Player p1, Player p2);    
            void playTurn();
            void printLastTurn();
            void printWiner();
            void printLog();
            void printStats();
            void playAll();
            int getNumOfDraws();

        private:
            Player p1;
            Player p2;
            string winersName;
            int numOfDraws;
    };
}