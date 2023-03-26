#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include "doctest.h"
#include <stdexcept>

using namespace ariel;

TEST_CASE("Before executing the game") {
    Player p1("Alice");
    Player p2("Bob");

    CHECK(p1.stacksize == 26);
    CHECK(p2.stacksize == 26);
    CHECK_EQ(p1.stacksize, p2.stacksize);
    CHECK_EQ(p1.)
}