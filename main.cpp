#include <utility>
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
#include "hash_ex.h"
#include "hash_ex.h"
#include "radixtree.h"


bool foo(const std::vector<double>& prices, int& buy, int& sel){
    bool bRet;
    double max_diff = 0;
    int cursor = 0;
    int size = prices.size ();

    for(auto i = 1; i < size; i++){
        if(prices.at (i) < prices.at (cursor)){   //seg finished
            cursor = i;
        }else{
            if(prices.at (i) - prices.at (cursor) > max_diff){
                max_diff = prices.at (i) - prices.at (cursor);
                buy = cursor;
                sel = i;
                bRet = true;
            }
        }
    }
    return bRet;
}

int main(){
    std::vector<double> prices{15, 14, 13, 12, 11, 10};
    int buy, sel;
    if(foo(prices, buy, sel)){
        std::cout << "buy:" << prices[buy] << ", sel:" << prices[sel] << ", benefit:" << prices[sel] - prices[buy] << std::endl;
    }else{
        std::cout << "No benefit at all" << std::endl;
    }
    std::cout << "finished." << std::endl;
    return 0;
}
