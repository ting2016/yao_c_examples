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
    yaostl::SimpleVector<Foo> vec;
    for(auto i = 0; i < 10; i++){
        vec.push_back (Foo(i));
    }

    std::cout << vec.size () << "---------------\n" << std::endl;
    vec.print ();
    int x;
    std::cin >> x;
    for(auto v: vec){
        std::cout << v << std::endl;
    }

    std::cin >> x;
    //testMalicious ();
//    testYaoStl ();
    std::cout << "Finished" << std::endl;
    return 0;
}

