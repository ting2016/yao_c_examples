#include "lambdatest.h"
#include <iostream>

void yao::lambda_ex::testLambda (){
    int a = 1, b = 11, c = 111;
    auto lamb = [a, &b, &c](auto x) mutable {   //NOTE mutable make a modifiable
        a += x; b += x; c += x;
    };

    lamb(3);
    std::cout << a << "\t" << b << "\t" << c << '\n';
}
