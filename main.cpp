#include <functional>
#include <utility>
#include "streamlogger.h"
#include "variadicparameters.h"
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
#include "ctortest.h"
#include "chronotest.h"
#include <unistd.h>
#include "malicious.h"
#include "lambdatest.h"

#include <stltest.h>
#include "foo.h"
#include "bar.h"
#include "fileio.h"
#include <functional>
#include <functionaltest.h>
#include <functional>
#include <initializer_list_test.h>
#include "signaltest.h"
#include "timertest.h"
#include <typeindex>
#include <typeinfo>
#include <algorithm>
#include "randomtest.h"
#include "sort_test.h"

void somefun(int& v){
    v+= 10;
}

//int main(/*int argc, char** argv*/){
//    yao::thread_ex::testSimpleThreadWithPara ();
//    std::cout << "Finished" << std::endl;
//    return 0;
//}



struct S {
    int m = 1;
};        // C++11: S is non-aggregate // C++14: S is AGGREGATE





struct X {
    operator int(){
        std::cout << "--->int" << std::endl;
        return 3;
    }
    operator double(){
        std::cout << "---> double" << std::endl;
        return 3.14159;
    }

    operator S(){
        std::cout << "---> S" << std::endl;
        return S{3};
    }

    operator std::string(){
        return "ahahahah";
    }
};






int main() {
	int A[10]{18,12,9,4,1,77,2,4,3,25};
	yao::heapsort(A, 10);
	for(auto i = 0; i < 10; i++){
		std::cout << A[i] << std::endl;
	}
	
    X a;
    double x = a;
    std::cout << x << std::endl;
    std::cout << (int)a << std::endl;
    std::cout << (std::string)a << std::endl;
    //S b{a};  // C++11: valid, copy constr S(a.operator S()) is called here
    // C++14: valid, aggregate initialization { a.operator int() }

    //    printf("%d\n", b.m);
}
