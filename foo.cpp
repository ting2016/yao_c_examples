#include "foo.h"

#define Out std::cout
#define End std::endl
#define FOO Foo
using F = Foo;
typedef Foo Foooooooooooooo;

FOO::FOO()
    :Foo(0){
    Out << "Default CTOR is called" << End;
}

F::Foo(const int& v)
    :v(v){
    Out << "CTOR(const int&) is called, v=" << v << End;
}

Foooooooooooooo::Foo(const Foo& other){
    if(&other != this){
        this->v = other.v;
    }
    Out << "Copy CTOR is called" << End;
}

Foo& F::operator =(const Foo& other){
    if(&other != this){
        this->v = other.v;
    }
    Out << "Assign CTOR is called" << End;
    return *this;
}

F::~Foo(){
    Out << "DTOR is called" << End;
}

void F::bar () const{
    Out << "\t\t" << __func__ << " say: my value is " << v << End;
}


void F::increaceValue(){
    v++;
    Out << __func__ << "is called" << End;
}

std::ostream& operator<<(std::ostream& os, const Foo& obj){
    return os << "foo:" << obj.v;
}
