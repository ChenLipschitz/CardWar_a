#ifndef CARD_HPP
#define CARD_HPP
#include<iostream>;
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


#endif