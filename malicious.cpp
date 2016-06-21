#include "malicious.h"
#include <vector>
#include <iostream>
#include <chrono>
#include <chronotest.h>
#include <yaostl.h>
Malicious::Malicious()
{

}

void Malicious::noexceptTest() const noexcept{
    throw YaoException("noexcept function should never throw exceptions. This will lead to crash...");
}

void Malicious::exceptionThrowableTest() const{
    throw YaoException("This exception can be caught...");
}


void testMalicious(){
    Malicious malicious;
    malicious.testPerformanceOfTraverseVector ();
    try{
        malicious.exceptionThrowableTest ();
    }catch(std::exception &e){
        std::cout << e.what () << std::endl;
    }

//    try{
//        malicious.noexceptTest ();
//    }catch(...){
//        std::cout << "Never can you see me..." << std::endl;
//    }
}



void Malicious::testPerformanceOfTraverseVector (){
    const int count = 10000000;
    std::vector<int> vec;
    yaostl::SimpleVector<int> vec2;
    for(auto i = 0; i < count; i++){
        vec.push_back (i);
        vec2.push_back (i);
    }

    YaoTime t;
    for(auto elem: vec){
        elem++;
    }
    std::cout << "iterator traverse vecter of " << count << " elements. milliSec:" << t.milliSecondsPassed () << std::endl;

    t.recordTime ();
    for(auto elem: vec2){
        elem++;
    }
    std::cout << "iterator traverse vecter2 of " << count << " elements. milliSec:" << t.milliSecondsPassed () << std::endl;

    t.recordTime ();
    int size = vec.size ();
    for(auto i = 0; i < size; i++){
        vec.at (i)++;
    }
    std::cout << "at(i) traverse vecter of " << count << " elements. milliSec:" << t.milliSecondsPassed () << std::endl;

    t.recordTime ();
    for(auto i = 0; i < size; i++){
        vec[i]++;
    }
    std::cout << "indices traverse vecter of " << count << " elements. milliSec:" << t.milliSecondsPassed () << std::endl;

    int* p = new int[count];
    int * pEnd = p + count;
    int* q = p;

    t.recordTime ();
    while(q < pEnd){
        ++(*q);
        q++;
    }
    std::cout << "pointer traverse array of " << count << " elements. milliSec:" << t.milliSecondsPassed () << std::endl;

    t.recordTime ();

    MyIterator from(p);
    MyIterator until(p + size);
    for (MyIterator it = from; it != until; it++){
        (*it)++;
    }
    std::cout << "my iterator traverse array of " << count << " elements. milliSec:" << t.milliSecondsPassed () << std::endl;

    delete []p;
}
