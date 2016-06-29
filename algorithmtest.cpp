#include "algorithmtest.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>


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


    std::vector<int> vec2;
    for(auto i = 0; i < 10; i++){
        vec2.push_back (i - 3);
    }

    //std::adjacent_find
    auto it = std::adjacent_find (vec2.begin(), vec2.end());
    if (it == vec2.end()){
        std::cout << "No repeated element found" << std::endl;
    }else{
        std::cout << "The repeated elements are: " << *it << '\n';
    }

    vec2.push_back (5);
    vec2.push_back (5);
    it = std::adjacent_find (vec2.begin(), vec2.end());
    if (it == vec2.end()){
        std::cout << "No repeated element found" << std::endl;
    }else{
        std::cout << "The repeated elements are: " << *it << '\n';
    }


    //std::adjacent_find using predicate comparison:
    it = std::adjacent_find (vec2.begin (), vec2.end(), equal_predicate);
    if (it == vec2.end()){
        std::cout << "No repeated element found" << std::endl;
    }else{
        std::cout << "The repeated elements are: " << *it << '\n';
    }

    //std::all_of
    if(std::all_of(vec2.begin (), vec2.end (), [](const int& i){return i < 10;})){
        std::cout << "All elem in vec is less than 10" << std::endl;
    }else{
        std::cout << "There are some elems in vec is not less than 10" << std::endl;
    }

    //std::any_of
    if(std::any_of(vec2.begin (), vec2.end (), less_0_predicate)){
        std::cout << "There exists an element lass than 0" << std::endl;
    }else{
        std::cout << "There does not exist an element lass than 0" << std::endl;
    }

    if (std::none_of(vec2.begin(), vec2.end(), [](int i){return i < 0;})){
        std::cout << "There are all positive elements in the range.\n";
    }else{
        std::cout << "There are negative elements in the range.\n";
    }

    int count = std::count (vec2.begin (), vec2.end (), 5);
    std::cout << "5 appears " << count << " times.\n";



}

bool yao::algorithm::less_0_predicate(const int& v){
    return v < 0;
}

bool yao::algorithm::equal_predicate(const int& v1, const int& v2){
    return v1 == v2;
}


void yao::algorithm::mem_test(){
    char s1[] = "hello";
    char s2[] = "world";

    std::memset(s2, 'c', sizeof(s2));

    for(std::size_t i = 0; i < sizeof(s2); i++){
        std::cout << s2[i] << std::endl;
    }
    std::memcpy(s2, s1, sizeof(s2));

    for(std::size_t i = 0; i < sizeof(s2); i++){
        std::cout << s2[i] << std::endl;
    }

    std::fill(s2, s2 + sizeof(s2), 'x');

    for(std::size_t i = 0; i < sizeof(s2); i++){
        std::cout << s2[i] << std::endl;
    }

    std::copy(s1, s1 + sizeof(s1), s2);
    for(std::size_t i = 0; i < sizeof(s2); i++){
        std::cout << s2[i] << std::endl;
    }


}
