#include "timertest.h"
#include <iostream>

void yao::timer::task1(void)
{
    std::cout << "timer trigered..." << std::endl;
}

void yao::timer::task2(int a)
{
    std::cout << a << std::endl;
}

void yao::timer::task3(const yao::Foo& f){
    f.bar ();
}

void yao::timer::test()
{
    Timer later_test1(5000, true/*false*/, &task1);
//    Timer later_test2(1000, true/*false*/, &task2, 101);
    Timer later_test3(1000, true/*false*/, &task3, yao::Foo(1111));

    for(auto i = 0; i < 10; i++){
        std::cout << "main thread runing*********" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
