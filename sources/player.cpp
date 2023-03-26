#include "player.hpp";
#include "string";

using namespace std;

    Player::Player(string name_){
        string name=name_;
    }

    string Player::getName(){
        return name;
    }

    int Player::stacksize(){
        return cards.size();
    }