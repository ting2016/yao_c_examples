#include "variadicparameters.h"
#include "ostreamoverride.h"
#include "templatetest.h"
#include <iostream>
using namespace std;
int main()
{
//    OStreamOverride::test();
    TemplateTest<int> tt(22, 33);
    std::cout << tt.getmax() << std::endl;
}
