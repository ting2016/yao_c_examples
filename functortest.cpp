#include "functortest.h"

void testFunctor(){
    myFunctorClass addFive( 5 );
    std::cout << addFive( 6 ) << std::endl;
}
