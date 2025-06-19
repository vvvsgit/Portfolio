#include "headers/functions.hpp"

#include <iostream>
#include <cstdlib>

void 
supermarket()
{
    std::srand(time(0));

    const size_t day = 720;

    std::queue<size_t> customers;
    size_t arrivalTime = get();
    size_t serviceTime = get();
    size_t leavingTime = arrivalTime + serviceTime;
    customers.push(leavingTime);

    size_t maxSize = customers.size();
    size_t maxWait = serviceTime;

    for (size_t minutes = arrivalTime; minutes < day; ++minutes) {
        if (minutes == arrivalTime) {
            arrivalTime += get();
            serviceTime = get();
            if (arrivalTime > leavingTime) {
                leavingTime = arrivalTime + serviceTime;
            } else {
                leavingTime = leavingTime + serviceTime;
            }
            customers.push(leavingTime);
            if (maxSize < customers.size()) {
                maxSize = customers.size();
            }
            if (maxWait < leavingTime - arrivalTime) {
                maxWait = leavingTime - arrivalTime;
            }
        }
        if (minutes == customers.front()) {
            customers.pop();
        }
    }

    std::cout << "Max size of queue is " << maxSize << " customer." << std::endl;
    std::cout << "Longest wait is " << maxWait << " minutes." << std::endl;
}

size_t 
get()
{
    return std::rand() % 4 + 1;
}

