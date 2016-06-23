#include "puretest.h"
#include <iostream>
void yao::test (){
    std::cout << "yao::test() is called" << std::endl;
}


void yao::name1::test(){
    std::cout << "yao::name1::test() is called" << std::endl;
}

void yao::name1::test2(){
    using namespace yao;
    std::cout << "yao::name1::test2() is called" << std::endl;
    test ();
    yao::test ();

}
