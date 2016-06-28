#include "ctortest.h"
#include <iostream>
#include <exceptiontest.h>
using namespace yao::ctor_ex;

Foo::Foo()
    : Foo(0){
    std::cout << "Foo() is called" << std::endl;
}

Foo::Foo(int size)
    : m_size(size){
    std::cout << "Foo(int) is called" << std::endl;
    if(m_size < 0){
        throw yao::exception_ex::UserException("size cannot be negtive");
        //assert(m_size >= 0);
    }else if(m_size == 0){
        m_capacity = 1;
    }else{
        m_capacity = m_size;
    }

    m_data = new int[m_size];
    std::cout << "m_data is newed:" << m_data << std::endl;
}

Foo::Foo(const Foo& other){
    std::cout << "Foo(const Foo& other) is called" << std::endl;
    this->m_size = other.m_size;
    if(m_size < 0){
        throw yao::exception_ex::UserException("size cannot be negtive");
    }else if(m_size == 0){
        m_capacity = 1;
    }else{
        m_capacity = m_size;
    }

    m_data = new int[m_size];
    std::cout << "m_data is newed:" << m_data << std::endl;
}

Foo& Foo::operator =(const Foo& other){
    std::cout << "operator =(const Foo& other) is called" << std::endl;
    if(this != &other){
        if(m_data){
            delete m_data;
            std::cout << "m_data is deleted:" << m_data << std::endl;
            m_data = nullptr;
        }

        m_size = other.m_size;

        if(m_size == 0){
            m_capacity = 1;
        }else{
            m_capacity = m_size;
            m_data = new int[m_size];
            std::cout << "m_data is newed:" << m_data << std::endl;
        }

    }
    return *this;
}

Foo::Foo(Foo&& other){
    std::cout << "Foo(Foo&& other) is called" << std::endl;
    this->m_size = other.m_size;
    this->m_capacity = other.m_capacity;
    this->m_data = other.m_data;
    other.m_size = 0;
    other.m_capacity = 0;
    other.m_data = nullptr;
}

Foo& Foo::operator =(Foo&& other){
    std::cout << "operator =(Foo&& other) is called" << std::endl;
    if(this != &other){
        this->m_size = other.m_size;
        this->m_capacity = other.m_capacity;
        this->m_data = other.m_data;
        other.m_size = 0;
        other.m_capacity = 0;
        other.m_data = nullptr;
    }
    return *this;
}

Foo& Foo::operator ()(){
    std::cout << "operator ()() is called" << std::endl;
    return *this;
}

Foo::~Foo(){
    std::cout << "~Foo() is called" << std::endl;
    if(m_data != nullptr){
        delete m_data;
        std::cout << "m_data is deleted:" << m_data << std::endl;
        m_data = nullptr;
    }
}

void Foo::print() const{
    std::cout << this << __func__ << " size:" << m_size << " capacity:" << m_capacity << std::endl;
}

void yao::ctor_ex::test(){
    //NOTE
    Foo f1(1); //call default ctor
    std::cout << "------------" << std::endl;
    Foo f2(f1); //call copy ctor
    std::cout << "------------" << std::endl;
    f2 = f1; //call assign ctor
    std::cout << "------------" << std::endl;
    Foo f3 = f1; //call copy ctor
    std::cout << "------------" << std::endl;
    Foo f4(Foo(2)); //Foo(2) will not call any ctor, simply pass 2 to f4, and will not create a temparary object
    std::cout << "------------" << std::endl;
    Foo f5(std::move(Foo(3)));

    test_move_ctor(f5); //not call move ctor
    test_move_ctor(Foo(20));// call move ctor
}

void yao::ctor_ex::test_move_ctor(Foo&& f){
    std::cout << "test2(Foo&&) is called" << std::endl;
    f.print ();
}

void yao::ctor_ex::test_move_ctor(Foo& f){
    std::cout << "test2(Foo&) is called" << std::endl;
    f.print ();
}
