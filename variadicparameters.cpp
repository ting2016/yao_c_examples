#include "variadicparameters.h"
#include <iostream>
VariadicParameters::VariadicParameters(){
}

void VariadicParameters::expand(){
     std::cout << std::endl;
}

void testVariadicParameters(){
    VariadicParameters t;
    t.expand("hello", "\t", 123);
}
