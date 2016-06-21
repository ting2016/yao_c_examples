#include "yaostl.h"
#include <vector>

#include "foo.h"
void testYaoStl(){
    yaostl::SimpleVector<Foo> vec;
//    std::vector<Foo> vec;
    for(auto i = 1; i <= 1; i++){
        vec.push_back(Foo(i));
    }

//    for(auto e: vec){
//        e.bar();
//    }
}
