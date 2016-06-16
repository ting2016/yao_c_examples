#include "puretest.h"
#include <iostream>
#include <exception>
#include <chrono>
#include <vector>
#include <unistd.h>
PureTest::PureTest()
{

}

void PureTest::test1() const{
    throw std::exception();
}

//If a function is declared as noexcept, and if it throw an exception, this application will be terminated even catche block is written in the caller.
void PureTest::test2() const noexcept{
    throw std::exception();
}

void testPure(){
    PureTest pt;

    try{
        pt.test1 ();
    }catch(std::exception &e){
        std::cout << "test1 " << "---------------" << e.what () << std::endl;
    }

    try{
        pt.test2 ();
    }catch(std::exception &e){
        std::cout << "test2 " << "---------------" << e.what () << std::endl;
    }
}

void testVector (){
#define N 100000000
    std::vector<int> vec;
    for(auto i = 0; i < N; i++){
        vec.push_back (i);
    }

    std::cout << "begin" << std::endl;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    for(auto elem: vec){
        elem++;
        elem--;
    }
    end = std::chrono::system_clock::now();
    std::chrono::duration <double> elapsed_seconds = end - start;
    std::chrono::microseconds t = std::chrono::duration_cast<std::chrono::microseconds> (elapsed_seconds);
    std::cout << "elapsed time1: " << t.count() << std::endl;

    int size = vec.size ();
    start = std::chrono::system_clock::now();
    for(auto i = 0; i < size; i++){
        vec.at (i)++;
        vec.at (i)--;
    }
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    t = std::chrono::duration_cast<std::chrono::microseconds> (elapsed_seconds);
    std::cout << "elapsed time2: " << t.count() << std::endl;


    start = std::chrono::system_clock::now();
    for(auto i = 0; i < size; i++){
        vec[i]++;
        vec[i]--;
    }
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    t = std::chrono::duration_cast<std::chrono::microseconds> (elapsed_seconds);
    std::cout << "elapsed time3: " << t.count() << std::endl;


    char* p = new char[N];
    char * pEnd = p + N;
    char* q = p;
    start = std::chrono::system_clock::now();
    while(q < pEnd){
//        ++(*q++);
        ++(*q);
        q++;
    }
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    t = std::chrono::duration_cast<std::chrono::microseconds> (elapsed_seconds);
    std::cout << "elapsed time4: " << t.count() << std::endl;


    start = std::chrono::system_clock::now();
    q = p;
    for(auto i = 0; i < N; i++){
        ++(*(q++));
    }
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    t = std::chrono::duration_cast<std::chrono::microseconds> (elapsed_seconds);
    std::cout << "elapsed time5: " << t.count() << std::endl;
}
