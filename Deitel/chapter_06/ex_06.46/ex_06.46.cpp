#include <iostream>

int
main()
{
    static int count = 1;
    std::cout << count++ << std::endl;
    main();
    return 0;
}

