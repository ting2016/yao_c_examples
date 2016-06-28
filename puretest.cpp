#include "puretest.h"
#include <iostream>
using namespace yao::puretest;
Foo::Foo()
    : v(0){
    std::cout << "Foo() is called" << std::endl;
    v = 0;
}

Foo::Foo(int v)
    : v(v){
    std::cout << "Foo(int) is called" << std::endl;
}

Foo::Foo(const Foo& other){
    this->v = other.v;
    std::cout << "Foo(& other) is called" << std::endl;
}

Foo& Foo::operator =(const Foo& other){
    std::cout << "operator =(const Foo& other) is called" << std::endl;
    if(this != &other){
        this->v = other.v;
    }
    return *this;
}

Foo::Foo(Foo&& other){
    std::cout << "operator =(Foo&& other) is called" << std::endl;
    this->v = other.v;
}

Foo& Foo::operator =(Foo&& other){
    std::cout << "operator =(Foo&& other) is called" << std::endl;
    if(this != &other){
        this->v = other.v;
    }
    return *this;
}

Foo& Foo::operator ()(){
    std::cout << "operator ()() is called" << std::endl;
    return *this;
}

Foo::~Foo(){
    std::cout << "~Foo() is called" << std::endl;
}

void Foo::bar() const{
    std::cout << this << " say: bar..." << std::endl;
}
void yao::puretest::test(){

//    Foo f1(10);
//    Foo f2(Foo(10)());
    Foo f3(Foo(10));
//    test2(f1);

    test2(Foo(20));
}

void yao::puretest::test2(Foo&& f){
    std::cout << "test2(Foo&) is called" << std::endl;
    std::move(f);
    f.bar();
}

void yao::puretest::test2(Foo& f){
    std::cout << "test2(Foo&&) is called" << std::endl;
}
