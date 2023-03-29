#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace ariel{
    class Player{
        private:
        string name;

        public:
        Player();
        Player(string name);
        int stacksize();
        int cardesTaken();
        string getName();
    };
}

