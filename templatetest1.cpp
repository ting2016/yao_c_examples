#include "templatetest1.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
TemplateTest1<T>::TemplateTest1 (T first, T second){
    a=first;
    b=second;
}

template <typename T>
T TemplateTest1<T>::getmax(){
    T retval;
    retval = (a > b) ? a : b;
    return retval;
}

// Explicit template instantiation
template class TemplateTest1<int>;
template class TemplateTest1<float>;
template class TemplateTest1<double>;
template class TemplateTest1<std::string>;

void testTemplate1(){
    int a1 = 22, b1 = 33;
    TemplateTest1<int> tmpl(a1, b1);
    std::cout << "max(" << a1 << "," << b1 << "):" << tmpl.getmax() << std::endl;

    std::string a2 = "hello", b2 = "hollo";
    TemplateTest1<std::string> tmpl2(a2, b2);
    std::cout << "max(" << a2 << "," << b2 << "):" << tmpl2.getmax() << std::endl;
}
