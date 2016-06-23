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
#include "puretest.h"
#include "chronotest.h"
#include <unistd.h>
#include "malicious.h"
#include "lambdatest.h"

#include <yaostl.h>
#include "foo.h"
#include "bar.h"

int main()
{
    testTemplate1 ();
    int a1 = 22, b1 = 33;
    TemplateTest1<int> tmpl(a1, b1);
    std::cout << "max(" << a1 << "," << b1 << "):" << tmpl.getmax() << std::endl;

    std::cout << "Finished" << std::endl;
    return 0;
}

