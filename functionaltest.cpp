#include "functionaltest.h"
#include <functional>
#include <iostream>

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
}
