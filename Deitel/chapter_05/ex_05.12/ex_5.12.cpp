#include <iostream>
#include <iomanip>

int
main()
{
    std::cout << std::endl;
    for (int i = 1; i <= 10; ++i) {
        for (int j = i; j > 0; --j) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int i = 10; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    for (int i = 10, w = 1; i >= 1; ++w, --i) {
        std::cout << std::setw(w);
        for (int j = 1; j <= i; ++j) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    for (int i = 1, w = 10; i <= 10; --w, ++i) {
        std::cout << std::setw(w);
        for (int j = i; j > 0; --j) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
    std::cout << "__________" << std::endl;

    for (int i = 1, w = 1; i <= 10; ++w, ++i) {
        std::cout << std::endl;
        for (int j = i; j > 0; --j) {
            std::cout << '*';
        }

        std::cout << std::setw(13 - w);
        for (int j = 1; j <= 11 - i; ++j) {
            std::cout << '*';
        }

        std::cout << std::setw(w * 2 + 2);
        for (int j = 1; j <= 11 - i; ++j) {
            std::cout << '*';
        }

        std::cout << std::setw(13 - w);
        for (int j = i; j > 0; --j) {
            std::cout << '*';
        }
    }
    std::cout << std::endl;
    std::cout << "__________" << std::endl;

    for (int i = 1, w = 1; i <= 10; ++w, ++i) {
        std::cout << std::endl;
        std::cout << std::setw(11 - w);
        for (int j = i; j > 0; --j) {
            std::cout << '*';
        }

        std::cout << std::setw(4);
        for (int j = i; j > 0; --j) {
            std::cout << '*';
        }
    }
    std::cout << std::endl;

    for (int i = 1, w = 1; i <= 10; ++w, ++i) {
        std::cout << std::endl;
        std::cout << std::setw(w);
        for (int j = 1; j <= 11 - i; ++j) {
            std::cout << '*';
        }

        std::cout << std::setw(4);
        for (int j = 1; j <= 11 - i; ++j) {
            std::cout << '*';
        }
    }

    std::cout << std::endl;
    return 0;
}

