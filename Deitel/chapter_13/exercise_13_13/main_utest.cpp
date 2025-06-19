#include "headers/Shape.hpp"

#include "headers/TwoDimensional.hpp"
#include "headers/Rectangle.hpp"
#include "headers/Circle.hpp"
#include "headers/Triangle.hpp"

#include "headers/ThreeDimensional.hpp"
#include "headers/Cuboid.hpp"
#include "headers/Sphere.hpp"
#include "headers/Pyramid.hpp"

#include <gtest/gtest.h>

TEST(Rectamgle, Area)
{
    Shape* shape = new Rectangle(11.0, 11.0);
    EXPECT_EQ(shape->getArea(), 121.0);
}

TEST(ClassName, AreaAndVolume)
{
    Shape* shape = new Cuboid(2.0, 5.0, 10.0);
    EXPECT_EQ(shape->getArea(), 10.0);
    EXPECT_EQ(dynamic_cast<ThreeDimensional*>(shape)->getVolume(), 100.0);
}

int
main(int argc, char** argv)
{
    std::cout << std::endl;

    Shape* shapes[] = { new Rectangle, new Cuboid, new Circle, new Triangle, new Sphere };
    TwoDimensional* d2[] = { new Rectangle, new Circle, new Triangle };
    ThreeDimensional* d3[] = { new Cuboid, new Sphere };
    
    std::cout << "Shapes" << std::endl;
    for (size_t i = 0; i < sizeof(shapes) / sizeof(Shape); ++i)
    {

        std::cout << typeid(*shapes[i]).name() << " - area - ";
        std::cout << shapes[i]->getArea() << std::endl;

        ThreeDimensional* three = dynamic_cast<ThreeDimensional*>(shapes[i]);
        if (three != NULL) {
            std::cout << typeid(*shapes[i]).name() << " - volume - ";
            std::cout << three->getVolume() << std::endl;
        }
    }
    std::cout << "\nTwoDimensionals" << std::endl;
    for (size_t i = 0; i < sizeof(d2) / sizeof(TwoDimensional); ++i)
    {
        std::cout << typeid(*d2[i]).name() << " - area - ";
        std::cout << d2[i]->getArea() << std::endl;
    }
    std::cout << "\nThreeDimensionals" << std::endl;
    for (size_t i = 0; i < sizeof(d3) / sizeof(ThreeDimensional); ++i)
    {
        std::cout << typeid(*d3[i]).name() << " - area - ";
        std::cout << d3[i]->getArea() << std::endl;
        std::cout << typeid(*d3[i]).name() << " - volume - ";
        std::cout << d3[i]->getVolume() << std::endl;
    }

    std::cout << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

