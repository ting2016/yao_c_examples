#include "variadicparameters.h"
#include "ostreamoverride.h"
#include "templatetest1.h"
#include "templatetest2.h"
#include "functionpointer.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    TemplateTest2<float>::test();
    TemplateTest1<float>::test();
    testFunctionPoint();
}
