#include "player.hpp"
#include "string"

using namespace ariel;

    Player::Player(){};
    Player::Player(string name_){
        string name=name_;
    }

    int Player::stacksize(){
        return 26;
    }

    int Player::cardesTaken(){
        return 0;
    }