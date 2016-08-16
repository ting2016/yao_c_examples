#include <iterator>
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
#include "binarysearchtree.h"

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

void printVec(const std::vector<int> &vec){
    std::cout << "--------------" << std::endl;
    for(auto& elem: vec){
        std::cout << elem<< std::endl;
    }
}

void printMap(const std::map<int, int> &map){
    std::cout << "--------------" << std::endl;
    for(auto& elem: map){
        std::cout << elem.second << std::endl;
    }
}


void eraseVec1(std::vector<int>& vec){
    for(std::vector<int>::iterator it = vec.begin (); it != vec.end ();){
        std::cout << "current node:" << *it << std::endl;
        if((*it) % 2){
            it = vec.erase (it);
        }else{
            ++it;
        }
    }
}


void eraseVec2(std::vector<int>& vec){
    for(std::vector<int>::iterator it = vec.begin (); it != vec.end ();){
        std::cout << "current node:" << *it << std::endl;
        if((*it) % 2){
            vec.erase (it);
        }else{
            ++it;
        }
    }
}

void eraseVec3(std::vector<int>& vec){
    for(std::vector<int>::iterator it = vec.begin (); it != vec.end ();){
        std::cout << "current node:" << *it << std::endl;
        if((*it) % 2){
            auto next = it + 1;
            vec.erase (it);
            it = next;
        }else{
            ++it;
        }
    }
}

void eraseMap1(std::map<int, int>& map){
    if(map.size () > 0){
        map.erase (map.cbegin ());
        eraseMap1 (map);
    }
}

void eraseMap2(std::map<int, int>& map){
    for(std::map<int, int>::const_iterator it = map.cbegin (); it != map.cend (); ){
        std::cout << "current node-->" << (*it).second << std::endl;
        if((*it).second % 2){
            const auto delIt = it;
            ++it;
            std::cout << "\tbefore removed:" << (*delIt).second << std::endl;
            map.erase (delIt);
            std::cout << "\tafter remove:" << (*delIt).second << std::endl;
        }else{
            it++;
        }
    }
}

void eraseMap4(std::map<int, int>& map){
    for(std::map<int,int>::iterator it = map.begin (); it != map.end ();){
        std::cout << "current node-->" << (*it).second << std::endl;
        if((*it).second % 2){
            std::cout << "\tbefore removed:" << (*it).second << std::endl;
            map.erase (it++);       //1. auto tmp = it.next, 2. delete it, 3. it = tmp 4. return it
            std::cout << "\tafter remove:" << (*it).second << std::endl;
        }else{
            ++it;
        }
    }
}

void eraseMap5(std::map<int, int>& map){    //this method is wrong, because it++ is too later
    for(std::map<int,int>::iterator it = map.begin (); it != map.end (); it++){
        std::cout << "current node-->" << (*it).second << std::endl;
        if((*it).second % 2){
            std::cout << "\tbefore removed:" << (*it).second << std::endl;
            map.erase (it);  //1. auto tmp = it.next, 2. delete it, 3. return tmp
            std::cout << "\tafter remove:" << (*it).second << std::endl;
        }
    }
}

int main(){
    std::vector<int> vec;

    for(auto i = 0; i < 10; i++){
        vec.push_back (i);
    }
    printVec (vec);
    eraseVec1 (vec);
    printVec (vec);

//    std::map<int, int> map;
//    for(auto i = 0; i < 10; i++){
//        map[i] = i;
//    }
//    map[6] = 77;
//    printMap (map);
//    eraseMap5 (map);
//    printMap (map);


    std::cout << "finished." << std::endl;
    return 0;
}
