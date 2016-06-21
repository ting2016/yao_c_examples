#include "foo.h"

Foo::Foo()
    :Foo(0){
    std::cout << "Default CTOR is called" << std::endl;
}

Foo::Foo(const int& v)
    :v(v){
    std::cout << "CTOR(const int&) is called, v=" << v << std::endl;
}

Foo::Foo(const Foo& other){
    if(&other != this){
        this->v = other.v;
    }
    std::cout << "Copy CTOR is called" << std::endl;
}

Foo& Foo::operator =(const Foo& other){
    if(&other != this){
        this->v = other.v;
    }
    std::cout << "Assign CTOR is called" << std::endl;
    return *this;
}

Foo::~Foo(){
    std::cout << "DTOR is called" << std::endl;
}

void Foo::bar () const{
    std::cout << __func__ << " say: my value is " << v << std::endl;
}


void Foo::increaceValue(){
    v++;
    std::cout << __func__ << "is called" << std::endl;
}
