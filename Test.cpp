#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include "doctest.h"
#include <stdexcept>

using namespace ariel;

TEST_CASE("Before executing the game check the intial peremeters") {
    Player p1("Ari");
    Player p2("Blake");
    Game game(p1, p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK_EQ(p1.stacksize(), p2.stacksize());
    CHECK_EQ(p1.cardesTaken(), 0);
    CHECK_EQ(p2.cardesTaken(), 0);
    CHECK_EQ(p1.cardesTaken(), p2.cardesTaken());
    CHECK_THROWS(game.printWiner());
    CHECK_THROWS(game.printLastTurn());
    CHECK_THROWS(game.printLog());
}

TEST_CASE("During the game"){
    Player p1("Ari");
    Player p2("Blake");
    Game game(p1, p2);
    game.playTurn();
    int difference=0;
    if(p1.stacksize()>p2.stacksize()){
        CHECK_GT(p1.stacksize(), p2.stacksize());
        CHECK_EQ(52, p1.stacksize()+p2.cardesTaken());
    }
    else{
        CHECK_LT(p1.stacksize(), p2.stacksize());
        CHECK_EQ(52, p2.stacksize()+p1.cardesTaken());
    } 
    CHECK_NE(p1.cardesTaken(), p2.cardesTaken());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
}

TEST_CASE("After the game was finished"){
    Player p1("Ari");
    Player p2("Blake");
    Game game(p1, p2);
    game.playAll();
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NE(p1.stacksize(), p2.stacksize());
    CHECK_NE(p1.cardesTaken(), p2.cardesTaken());
}