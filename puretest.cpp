#include "puretest.h"
#include <iostream>
#include <exception>
PureTest::PureTest()
{

}

void PureTest::test1() const{
    throw std::exception();
}

//If a function is declared as noexcept, and if it throw an exception, this application will be terminated even catche block is written in the caller.
void PureTest::test2() const noexcept{
    throw std::exception();
}

void testPure(){
    PureTest pt;

    try{
        pt.test1 ();
    }catch(std::exception &e){
        std::cout << "test1 " << "---------------" << e.what () << std::endl;
    }

    try{
        pt.test2 ();
    }catch(std::exception &e){
        std::cout << "test2 " << "---------------" << e.what () << std::endl;
    }
}
