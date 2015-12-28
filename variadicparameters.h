#pragma once
#include <iostream>
class VariadicParameters{
public:
    VariadicParameters();
    template<typename FIRST_PARA, typename... PARAS>
    void expand(FIRST_PARA firstPara, PARAS... paras);

    static void test();
private:
    void expand();
};

template<typename FIRST_PARA, typename... PARAS>
void VariadicParameters::expand(FIRST_PARA firstPara, PARAS... paras){
    std::cout << firstPara;
    expand(paras...);
}
