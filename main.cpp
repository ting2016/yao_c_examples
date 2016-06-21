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
int main()
{
    testGragh ();
    testnmsp::Test2 t;
    t.print ();
    testnmsp::Test2 t2(100);
    t2.print ();

    return 0;
}

