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

TEST(AllPackages, Polymorph)
{
    Citizen to("a", "b", "c", "d", 1);
    Citizen from("f", "g", "h", "i", 2);
    Package package(to, from);
    TwoDayPackage twoDay(to, from, 2.0, 2.0, 2.0);
    OvernightPackage nightDay(to, from, 3.0, 3.0, 3.0);
    Package* packages[3] = { &package, &twoDay, &nightDay };

    double allCost = 0;
    for (size_t i = 0; i < 3; ++i) {
        allCost += packages[i]->calculateCost();

        std::ostringstream buffer1;
        std::streambuf* oldBuffer1 = std::cout.rdbuf(buffer1.rdbuf());
        packages[i]->printLabel();
        const std::string pointerOutput = buffer1.str();
        std::cout.rdbuf(oldBuffer1);

        std::ostringstream buffer2;
        std::streambuf* oldBuffer2 = std::cout.rdbuf(buffer2.rdbuf());
        (*packages[i]).printLabel();
        const std::string objectOutput = buffer2.str();
        std::cout.rdbuf(oldBuffer2);

        EXPECT_EQ(pointerOutput, objectOutput);
    }
    EXPECT_EQ(allCost, 25);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

