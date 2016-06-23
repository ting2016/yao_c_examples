#include "algorithmtest.h"
#include <vector>
#include <iostream>
#include <algorithm>


void yao::algorithm::algoOutput(int i){
    std::cout << i << "\t";
}

void yao::algorithm::algoIncreace(int& i){
    i++;
}

void yao::algorithm::Algorithm::operator()(int& i) const{
    --i;
}


void yao::algorithm::test(){
    std::vector <int> vec;
    for(auto i = 10; i <= 100; i += 10){
        vec.push_back (i);
    }
    for_each(vec.cbegin (), vec.cend (), algoOutput);

    std::cout << std::endl << "-----------------------" << std::endl;

    for_each(vec.begin (), vec.end (), algoIncreace);

    for_each(vec.cbegin (), vec.cend (), algoOutput);

    std::cout << std::endl << "-----------------------" << std::endl;

    Algorithm algorithmTestObj;
    for_each(vec.begin (), vec.end (), algorithmTestObj);

    for_each(vec.cbegin (), vec.cend (), algoOutput);
}
