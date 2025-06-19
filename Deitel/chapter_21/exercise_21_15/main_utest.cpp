#include "headers/functions.hpp"

#include <gtest/gtest.h>

TEST(TEST, TEST)
{
    supermarket();
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

