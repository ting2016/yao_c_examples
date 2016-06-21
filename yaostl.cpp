#include "yaostl.h"

#include "foo.h"
void testYaoStl(){
    yaostl::SimpleVector<Foo> vec;
    for(auto i = 1; i < 10000; i++){
        vec.push_back(Foo(i));
    }

    for(auto e: vec){
        e.bar();
    }
}
