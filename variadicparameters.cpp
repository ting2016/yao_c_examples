#include "variadicparameters.h"
#include <iostream>

using namespace yao::variadic;
void VariadicParameters::expand(){
     std::cout << std::endl;
}

void yao::variadic::test(){
    VariadicParameters t;
    t.expand("hello", "\t", 123);
}
