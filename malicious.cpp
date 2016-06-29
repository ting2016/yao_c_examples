#include "malicious.h"
#include <vector>
#include <iostream>
#include <chronotest.h>
#include <stltest.h>
#include "foo.h"
#include "bar.h"
#include <iterator>
#include "stltest.h"
#include <cstring>

void yao::malicious::test (){
    testPerformanceOfTraverseVector ();
}

void yao::malicious::testPerformanceOfTraverseVector (){
    const int count = 100000000;
    std::vector<int> vec;
    yao::stl::SimpleVector<int> vec2;
    for(auto i = 0; i < count; i++){
        vec.push_back (i);
        vec2.push_back (i);
    }

    yao::chrono::YaoTime t;
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

void yao::malicious::testVectorTraverse(){
    std::vector<yao::Foo> vec;
    for(auto i = 0; i < 10; i++){
        vec.push_back (yao::Foo(i + 1));
    }

    //indices visit
    for(size_t /*auto*/ i = 0; i < vec.size (); i++){
        std::cout << vec[i] << std::endl;
        //std::cout << vec.at (i) << std::endl;
    }

    //iterator 1
    for(std::vector<yao::Foo>::iterator it = vec.begin (); it != vec.end (); it++){
        std::cout << *it << std::endl;
    }

    //iterator 2
    for(auto it = vec.begin (); it != vec.end (); it++){
        std::cout << *it << std::endl;
    }

    //iterator 3
    for(auto it = std::cbegin(vec); it != std::cend(vec); ++it){
        std::cout << (*it) << std::endl;
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
    std::for_each(vec.begin(), vec.end(), [](yao::Foo const& elem) {
         std::cout << elem << std::endl;
    });


    //iterator way apply different strides
    auto head = std::begin(vec);
    auto tail = std::end(vec);
    while(head < tail){
        std::cout << *head << std::endl;
        std::advance(head, 2);
    }
}

void yao::malicious::testIterator(){
    std::vector<yao::Bar> vec;
    for(auto i = 0; i < 10; i++){
        vec.push_back (yao::Bar(i + 1));
    }

    std::cout << "std::distance(vec.cbegin(), vec.cend()):" << std::distance(vec.cbegin (), vec.cend ()) << std::endl;
    std::cout << "std::begin(vec):" << *std::cbegin(vec) << std::endl;
    std::cout << "vec.begin():" << *vec.cbegin ()<< std::endl;
    std::cout << "std::next(vec.begin(), 1):" << *std::next(vec.begin (), 1) << std::endl;
    std::cout << "std::prev(vec.end(), 1):" << *std::prev(vec.end(), 1) << std::endl;

    auto it = vec.begin ();
    std::advance (it, 2);
    std::cout << "std::advance(auto it = vec.begin(), 2) to begin:" << *it << std::endl;


    std::vector<yao::Bar> vec2;
    std::copy(vec.begin (), vec.end (), std::back_inserter(vec2)); // TODO front_inserter failed on vector

    int a[10];
    for(auto i = 0; i < 10; i++){
        a[i] = i + 1;
    }

    std::cout << "simple iterator test" << std::endl;
    MyIterator from(a);
    MyIterator until(a + 10);
    for (MyIterator it = from; it != until; it++){
        std::cout << *it << std::endl;
    }

    yao::stl::vector<yao::Bar> vec3;
    for(auto i = 0; i < 10; i++){
        vec3.push_back (yao::Bar(i + 1));
    }

    for(auto& v: vec3){
        std::cout << v << std::endl;
    }

    std::cout << "std::distance(vec.cbegin(), vec.cend()):" << std::distance(vec3.begin (), vec3.end ()) << std::endl;
    std::cout << "std::begin(vec):" << *std::begin(vec3) << std::endl;
    std::cout << "vec.begin():" << *vec3.begin ()<< std::endl;
    std::cout << "std::next(vec.begin(), 1):" << *std::next(vec3.begin (), 1) << std::endl;
}

void yao::malicious::testIOStreamIterator(){

    std::vector <yao::Bar> vec;
    std::istream_iterator<int> eos;              // end-of-stream iterator
    std::cout << "Please input numbers(-1 to quit):" << std::endl;
    std::istream_iterator<int> iit (std::cin);   // stdin iterator
    while(true){
        if(iit == eos){
            std::cerr << "bad format" << std::endl;
            break;
        }else{
            if(*iit == -1){
                break;
            }
            vec.push_back (yao::Bar(*iit));
        }
        ++iit;
    }


    std::ostream_iterator<yao::Bar> out_it (std::cout, "\n");
    std::copy (vec.begin(), vec.end(), out_it);
}


//std::copy is faster than std::memcpy (why, it fill memory in sizeof(long) interval, not in 1 Byte)
//std::fill is slower than std::memset
void yao::malicious::mem_speed_test (){
    const int size = 1000000;
    char *s1 = new char[size];
    char *s2 = new char[size];

    for(auto i = 0; i < size; i++){
        s1[i] = i % 26 + 65;
    }
    yao::chrono::YaoTime t;

    std::memset(s2, 0, size);
    std::cout << "memset milliSec:" << t.milliSecondsPassed () << std::endl;

    t.recordTime ();


    long* p = (long*)s2;
    long* q = (long*)(s2 + size);
    int long_leng = sizeof(long);
    while(p < q){
        *p++ <<= long_leng;
    }
    std::cout << "pointer milliSec:" << t.milliSecondsPassed () << std::endl;

    t.recordTime ();

    std::fill(s2, s2 + size, 0);
    std::cout << "std::fill milliSec:" << t.milliSecondsPassed () << std::endl;

    t.recordTime ();
    std::memcpy(s2, s1, size);
    std::cout << "memcpy milliSec:" << t.milliSecondsPassed () << std::endl;

    t.recordTime ();
    std::copy(s1, s1 + size, s2);
    std::cout << "std::copy milliSec:" << t.milliSecondsPassed () << std::endl;
}

void yao::malicious::testPair (){
    std::pair <int, int> p1{1, 3};
    auto p2 = std::make_pair(2, 'M');
    std::cout << p1.first << ", " << p1.second << std::endl;
    std::cout << p2.first << ", " << p2.second << std::endl;
}
