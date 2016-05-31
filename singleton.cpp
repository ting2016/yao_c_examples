#include "singleton.h"

Singleton::Singleton():
    v(0){
    std::cout << __func__ << " is called" << std::endl;
}

Singleton& Singleton::instance(){
    std::cout << __func__ << " is called" << std::endl;
    static Singleton sing;
    return sing;
}

Singleton::~Singleton(){
    std::cout << __func__ << " is called" << std::endl;
}

void Singleton::setValue(int v){
    this->v = v;
}

int Singleton::getValue() const{
    return v;
}

void testSingleton(){

    Singleton::instance().setValue(100);
    std::cout << "value:" << Singleton::instance().getValue() << std::endl;
}
