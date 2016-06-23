#pragma once
#include <iostream>

namespace yao{
    namespace variadic{
        class VariadicParameters;
        void test();
    }
}
class yao::variadic::VariadicParameters{
public:
    VariadicParameters(){}
    template<typename FIRST_PARA, typename... PARAS>
    void expand(FIRST_PARA firstPara, PARAS... paras);

private:
    void expand();
};

template<typename FIRST_PARA, typename... PARAS>
void yao::variadic::VariadicParameters::expand(FIRST_PARA firstPara, PARAS... paras){
    std::cout << firstPara;
    expand(paras...);
}

