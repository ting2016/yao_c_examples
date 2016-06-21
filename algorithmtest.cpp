#include "algorithmtest.h"
#include <vector>
#include <iostream>
#include <algorithm>

void algoOutput(int i){
    std::cout << i << "\t";
}

void algoIncreace(int& i){
    i++;
}

void AlgorithmTest::operator()(int& i) const{
    --i;
}


void testAlgorithm(){
    std::vector <int> vec;
    for(auto i = 10; i <= 100; i += 10){
        vec.push_back (i);
    }
    for_each(vec.cbegin (), vec.cend (), algoOutput);

    std::cout << std::endl << "-----------------------" << std::endl;

    for_each(vec.begin (), vec.end (), algoIncreace);

    for_each(vec.cbegin (), vec.cend (), algoOutput);

    std::cout << std::endl << "-----------------------" << std::endl;

    AlgorithmTest algorithmTestObj;
    for_each(vec.begin (), vec.end (), algorithmTestObj);

    for_each(vec.cbegin (), vec.cend (), algoOutput);
}
