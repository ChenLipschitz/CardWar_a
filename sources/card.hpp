#pragma once
#include <iostream>
using namespace std;

namespace ariel{
    class Card{
        private:
        string color;
        string shape;
        int value;

        public:
        Card();
        int getValue();
        string getColor();
        string getShape();
    };
}