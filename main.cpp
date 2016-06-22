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
#include "bar.h"

int main()
{
    yao_bar::Bar bar(20);
    std::cout << bar << std::endl;

    std::cout << "Finished" << std::endl;
    return 0;
}

