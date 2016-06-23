#include "singleton.h"
#include <iostream>
using namespace yao::singleton;
SingletonBase::SingletonBase():
    id(0),
    className("SingletonBase"){
    std::cout << className << "::" << __func__ << " is called" << std::endl;
}

SingletonBase& SingletonBase::instance(){
    std::cout << "SingletonBase" << "::" << __func__ << " is called" << std::endl;
    static SingletonBase singRef;
    return singRef;
}

SingletonBase* SingletonBase::instancePoint(){
    std::cout << "SingletonBase" << "::" << __func__ << " is called" << std::endl;
    return &instance();
}

SingletonBase::~SingletonBase(){
    std::cout << className << "::" << __func__ << " is called" << std::endl;
}

void SingletonBase::setId(int id){
    this->id = id;
}

int SingletonBase::getId() const{
    return id;
}

void SingletonBase::bar(){
    std::cout << className << "::" << __func__ << " say hi" << std::endl;
    std::cout << "\t id:" << id << std::endl;
}


void SingletonDerived::setValue(int v){
    value = v;
}

void SingletonDerived::bar(){
    std::cout << className << "::" << __func__ << " say hi" << std::endl;
    std::cout << "\t id:" << id << " , value:" << value << std::endl;
}

SingletonDerived::SingletonDerived():
    value(0),
    className("SingletonDerived"){

}

SingletonDerived& SingletonDerived::instance(){
    std::cout << "SingletonDerived" << "::" << __func__ << " is called" << std::endl;
    static SingletonDerived b;
    return b;
}

SingletonDerived* SingletonDerived::instancePoint(){
    std::cout << "SingletonDerived" << "::" << __func__ << " is called" << std::endl;
    return &instance();
}

SingletonDerived::~SingletonDerived(){
    std::cout << className << "::" << __func__ << " is called" << std::endl;
}

void yao::singleton::test(){
    SingletonBase::instance().bar();
    SingletonBase::instance().setId(100);
    SingletonBase* pSingleBase = SingletonBase::instancePoint();
    pSingleBase->bar();

    std::cout << "-------------------------" << std::endl;
    SingletonDerived::instance().bar();
    SingletonDerived::instance().setId(1000);
    SingletonDerived::instance().setValue(2000);

    SingletonDerived* pSingleDerived = SingletonDerived::instancePoint();
    pSingleDerived->bar();

    std::cout << "-------------------------" << std::endl;
    SingletonBase::instancePoint()->bar();
}
