#include "streamlogger.h"
#include "variadicparameters.h"
#include "ostreamoverride.h"
#include "templatetest1.h"
#include "templatetest2.h"
#include "functionpointer.h"
#include "definetest.h"
#include "version.h"
#include "singleton.h"
#include "graphic.h"
#include <iostream>
#include <string>
#include <hashtest.h>
#include <map>
#include "maptest.h"
#include "functortest.h"
#include "threadtest.h"
#include "algorithmtest.h"
#include "puretest.h"
#include "chronotest.h"
#include <unistd.h>
#include "malicious.h"
#include "lambdatest.h"

#include <yaostl.h>
#include "foo.h"


int main()
{

    {
        yaostl::SimpleVector<Foo> vec;
        for(auto i = 0; i < 1; i++){
            vec.push_back (Foo(i));
        }

        std::cout << std::endl << std::endl;

        for(auto v: vec){
            std::cout << v << std::endl;
        }
    }
    std::cout << "---------------\n" << std::endl;
    {
        std::vector<Foo> vec2;
        for(auto i = 0; i < 1; i++){
            vec2.push_back (Foo(i));
        }

        std::cout << std::endl << std::endl;

        for(auto v: vec2){
            std::cout << v << std::endl;
        }
    }


//    std::cin >> x;
    //testMalicious ();
//    testYaoStl ();
    std::cout << "Finished" << std::endl;
    return 0;
}

