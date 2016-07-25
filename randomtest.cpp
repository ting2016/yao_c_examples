#include "randomtest.h"
#include <random>
#include <iostream>
#include <chrono>

void yao::random_ex::testRandom(){

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::minstd_rand0 randNum (seed);  // minstd_rand0 is a standard linear_congruential_engine

    for(auto i = 0; i < 10; i++){
        std::cout << "A time seed produced: " << randNum() << std::endl;
    }

    std::random_device rd;

    std::cout << rd.min () << std::endl;
    std::cout << rd.max () << std::endl;
}
