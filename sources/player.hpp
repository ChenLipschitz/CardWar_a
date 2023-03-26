#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>;

using namespace std;

namespace ariel{
    class Player{
    public:
        Player(string name);
        int stacksize();
        int cardesTaken();
        string getName();
    

    private:
        string name;
        //stack<card> myStack;
    };
}


#endif