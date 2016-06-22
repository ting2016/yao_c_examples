#include "malicious.h"
#include <vector>
#include <iostream>
#include <chronotest.h>
#include <yaostl.h>
#include "foo.h"

void yao_malicious::test (){
    testPerformanceOfTraverseVector ();
}

void yao_malicious::testPerformanceOfTraverseVector (){
    const int count = 100000000;
    std::vector<int> vec;
    yao_stl::SimpleVector<int> vec2;
    for(auto i = 0; i < count; i++){
        vec.push_back (i);
        vec2.push_back (i);
    }

    yao_chrono::YaoTime t;
    for(auto elem: vec){
        elem++;
    }
    std::cout << "iterator traverse vecter of " << count << " elements. milliSec:" << t.milliSecondsPassed () << std::endl;

    t.recordTime ();
    for(auto elem: vec2){
        elem++;
    }
    std::cout << "iterator traverse yao vecter of " << count << " elements. milliSec:" << t.milliSecondsPassed () << std::endl;

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
    while(q != pEnd){
        (*q)++;
        q++;
    }
    std::cout << "pointer traverse array of " << count << " elements. milliSec:" << t.milliSecondsPassed () << std::endl;
    delete []p;
}

void yao_malicious::testVectorTraverse(){
    std::vector<Foo> vec;
    for(auto i = 0; i < 10; i++){
        vec.push_back (Foo(i + 1));
    }

    //indices visit
    for(size_t /*auto*/ i = 0; i < vec.size (); i++){
        std::cout << vec[i] << std::endl;
        //std::cout << vec.at (i) << std::endl;
    }

    //iterator 1
    for(std::vector<Foo>::iterator it = vec.begin (); it != vec.end (); it++){
        std::cout << *it << std::endl;
    }

    //iterator 2
    for(auto it = vec.begin (); it != vec.end (); it++){
        std::cout << *it << std::endl;
    }

    //range-for loop 1 (get object copy)
    for(auto v: vec){
        std::cout << v << std::endl;
    }

    //Highly encourged
    //range-for loop 1 (get object ref)
    for (auto& v: vec) {
        std::cout << v << std::endl;
    }

    //Highly encourged
    //lambda visit
    std::for_each(vec.begin(), vec.end(), [](Foo const& elem) {
         std::cout << elem << std::endl;
    });
}
