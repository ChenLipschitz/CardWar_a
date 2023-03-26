#pragma once
#include <iostream>;
using namespace std;

namespace ariel{
    class Game{
    public:    
        void playTurn();
        void printLastTurn();
        void printWiner();
        void printLog();
        void printStats();
        void playAll();

    private:
        string getWinersName();
    };
}