#include "initializer_list_test.h"
#include <iostream>
void yao::initializer_list::test(){
    Foo <int> foo{10, 20, 30};
    for(auto f: foo){
        std::cout << f << std::endl;
    }
}
