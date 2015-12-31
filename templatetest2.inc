#include "templatetest2.h"
#include <iostream>
#include <string>

template <class T>
TemplateTest2<T>::TemplateTest2(){
}

template <class T>
void TemplateTest2<T>::SetValue( T obj_i ){
    m_Obj = obj_i;
}

template <class T>
T TemplateTest2<T>::Getalue(){
    return m_Obj;
}


void testTemplate2(){
    TemplateTest2<int> tmpObj1;
    tmpObj1.SetValue(100);
    std::cout << tmpObj1.Getalue() << std::endl;

    TemplateTest2<std::string> tmpObj2;
    tmpObj2.SetValue("hello world");
    std::cout << tmpObj2.Getalue() << std::endl;
}
