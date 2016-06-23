#include "functortest.h"

void yao::functor_ex::test(){
    Functor addFive( 5 );
    std::cout << addFive( 6 ) << std::endl;
}
