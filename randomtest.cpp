#include "randomtest.h"
#include <random>
#include <iostream>

void testRandom(){
    std::random_device rd;
    std::cout << rd.min () << std::endl;
    std::cout << rd.max () << std::endl;
}
