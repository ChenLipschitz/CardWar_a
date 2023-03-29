#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include "doctest.h"
#include <stdexcept>

using namespace ariel;

TEST_CASE("Before executing the game check the initial peremeters") {
    Player p1("Ari");
    Player p2("Blake");
    Game game1(p1, p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK_EQ(p1.cardesTaken(), 0);
    CHECK_EQ(p2.cardesTaken(), 0);
    CHECK_THROWS(game1.printWiner());
    CHECK_THROWS(game1.printLastTurn());
    CHECK_THROWS(game1.printLog());     //throw an exception if the game hasn't started yet
}

TEST_CASE("A player can play only one game at a time"){
    Player p1("Ari");
    Player p2("Blake");
    Player p3("Clair");
    Game game1(p1, p2);
    Game game2(p2, p3);
    game2.playTurn();
    CHECK_THROWS(game1.playAll());
    CHECK_THROWS(game1.printLastTurn());
    CHECK_THROWS(game1.printWiner());
}

TEST_CASE("A player can play only one game"){
    Player p1("Ari");
    Player p2("Blake");
    Player p3("Clair");
    Game game1(p1, p2);
    Game game2(p1, p3);
    game1.playAll();
    CHECK_THROWS(game2.playTurn());
    CHECK_THROWS(game2.printLastTurn());
    CHECK_THROWS(game2.printLog());
    CHECK_THROWS(game2.printStats());
    CHECK_THROWS(game1.printWiner());
}

TEST_CASE("During the game"){
    Player p1("Ari");
    Player p2("Blake");
    Game game(p1, p2);
    game.playTurn();
    if(p1.stacksize()>p2.stacksize()){
        CHECK_GT(p2.cardesTaken(), p1.cardesTaken());
        CHECK_EQ(52, p1.cardesTaken()+p2.cardesTaken());
    }
    else{
        CHECK_GT(p1.cardesTaken(), p2.cardesTaken());
        CHECK_EQ(52, p2.cardesTaken()+p1.cardesTaken());
    } 
    CHECK_NE(p1.cardesTaken(), p2.cardesTaken());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
}

TEST_CASE("Check the following operations after the game is done"){
    Player p1("Ari");
    Player p2("Blake");
    Game game(p1, p2);
    game.playAll();
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NE(p1.cardesTaken(), p2.cardesTaken());
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
}

TEST_CASE("Check if more turns can be made, after the game has ended"){
    Player p1("Ari");
    Player p2("Blake");
    Game game(p1, p2);
    game.playAll();
    CHECK_THROWS(game.playTurn());
    CHECK_THROWS(game.playAll());
}