#include "position.hpp"
#include <gtest/gtest.h>

TEST(Position, Position) {
    EXPECT_TRUE(Position(1, 1) == Position(1, 1));
}
