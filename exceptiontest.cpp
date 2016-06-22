#include "exceptiontest.h"
#include <iostream>
using namespace yao_exception;
NonExceptTest::NonExceptTest(){
}

void NonExceptTest::noexceptTest() const noexcept{
    throw UserException("noexcept function should never throw exceptions. This will lead to crash...");
}

void NonExceptTest::exceptionThrowableTest() const{
    throw UserException("This exception can be caught...");
}

void yao_exception::test(){
    NonExceptTest obj;
    try{
        obj.exceptionThrowableTest ();
    }catch(std::exception &e){
        std::cout << e.what () << std::endl;
    }

    try{
        obj.noexceptTest ();
    }catch(...){
        std::cout << "Never can you see me..." << std::endl;
    }
}
