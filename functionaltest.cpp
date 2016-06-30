#include "functionaltest.h"
#include <functional>
#include <iostream>
#include <algorithm>

double yao::functional::my_divide (double x, double y) {
    return x / y;
}
void yao::functional::test (){
    auto fn_five = std::bind (my_divide, 10, 2);               // returns 10/2
    std::cout << fn_five() << '\n';

    auto fn_half = std::bind (my_divide, std::placeholders::_1, 2);               // returns x/2
    std::cout << fn_half(10) << '\n';

    auto fn_invert = std::bind (my_divide, std::placeholders::_2, std::placeholders::_1);            // returns y/x
    std::cout << fn_invert(10, 2) << '\n';

    auto fn_rounding = std::bind<int> (my_divide, std::placeholders::_1, std::placeholders::_2);     // returns int(x/y)
    std::cout << fn_rounding(10, 3) << '\n';

    Pair ten_two {10, 2};

    // binding members:
    auto bound_member_fn = std::bind (&Pair::multiply, std::placeholders::_1); // returns x.multiply()
    std::cout << bound_member_fn(ten_two) << '\n';           // 20

    auto bound_member_data = std::bind (&Pair::b, ten_two); // returns ten_two.a
    std::cout << bound_member_data() << '\n';                // 10

    int foo(10);
    auto/*not int*/ foo_cref = std::cref(foo);
    auto/*not int*/ foo_ref = std::ref(foo);
    foo_ref += 100;
    //foo_ref = 100; //ill format
    std::cout << "foo:" << foo << std::endl;
    std::cout << "foo_cref:" << foo_cref << std::endl;
    std::cout << "foo_ref:" << foo_ref << std::endl;

    int a[] = {10, 20, 5, 15, 25};
    int b[] = {15, 10, 20};
    std::sort (a, a + (sizeof a)/sizeof(int), std::less<int>());  // 5 10 15 20 25
    std::sort (b, b + (sizeof b)/sizeof(int), std::less<int>());  //   10 15 20
    if (std::includes (a, a+5, b, b + 3, std::less<int>()))
        std::cout << "a includes b" << std::endl;


    std::function<int(int)> fn1 = half;                    // function
    std::function<int(int)> fn2 = &half;                   // function pointer
    std::function<int(int)> fn3 = third_t();               // function object
    std::function<int(int)> fn4 = [](int x){return x/4;};  // lambda expression
    std::function<int(int)> fn5 = std::negate<int>();      // standard function object

    std::cout << "fn1(60): " << fn1(60) << '\n';
    std::cout << "fn2(60): " << fn2(60) << '\n';
    std::cout << "fn3(60): " << fn3(60) << '\n';
    std::cout << "fn4(60): " << fn4(60) << '\n';
    std::cout << "fn5(60): " << fn5(60) << '\n';

    // stuff with members:
    std::function<int(MyValue&)> value = &MyValue::value;  // pointer to data member
    std::function<int(MyValue&)> fifth = &MyValue::fifth;  // pointer to member function

    MyValue sixty {60};

    std::cout << "value(sixty): " << value(sixty) << '\n';
    std::cout << "fifth(sixty): " << fifth(sixty) << '\n';

}


int yao::functional::half(int x) {
    return x/2;
}

