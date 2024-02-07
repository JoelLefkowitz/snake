#include "numbers.hpp"
#include <gtest/gtest.h>

TEST(Numbers, NegModulo) {
    EXPECT_EQ(neg_modulo(10, 2), 0);
    EXPECT_EQ(neg_modulo(-10, 2), 0);

    EXPECT_EQ(neg_modulo(10, 3), 1);
    EXPECT_EQ(neg_modulo(-10, 3), 2);
}
