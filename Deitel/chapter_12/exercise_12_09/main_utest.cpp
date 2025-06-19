#include "headers/TwoDayPackage.hpp"
#include "headers/OvernightPackage.hpp"

#include <gtest/gtest.h>

TEST(Package, Cost)
{
    Citizen batman("Bruce Wayne", "Wayne mansion", "Gotham", "New Jersey", 0);
    Citizen superman("Clark Kent", "Krypton", "Metropolis", "Delaware", 9765);
    Package day(batman, superman);
    EXPECT_EQ(day.calculateCost(), 1.0);
}

TEST(TwoDayPackage, Cost)
{
    Citizen you("Your", "YourPlace", "YourCity", "YourState", 1234);
    Citizen me("My", "MyPlace", "MyCity", "MyState", 1235);
    TwoDayPackage twoDay(you, me, 3.0, 2.5, 5.1);
    EXPECT_EQ(twoDay.calculateCost(), 12.6);
}

TEST(OvernightPackage, Cost)
{
    Citizen he("His", "HisPlace", "HisCity", "HisState", 1236);
    Citizen she("Her", "HerPlace", "HerCity", "HerState", 1237);
    OvernightPackage nightDay(he, she, 3.0, 2.5, 3.3);
    EXPECT_EQ(nightDay.calculateCost(), 17.4);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

