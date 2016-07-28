#include "functortest.h"

void yao::functor_ex::test(){
    Functor addFive( 5 );
    std::cout << addFive( 6 ) << std::endl;

    Functor2 a(123);
    double x = a;
    std::cout << x << std::endl;
    std::cout << (int)a << std::endl;
    std::cout << (std::string)a << std::endl;
}
