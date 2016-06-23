#include "bar.h"

using namespace yao;

Bar::Bar(const Bar& other){
    this->v = other.v;
}

Bar& Bar::operator = (const Bar& other){
    if(this != &other){
        this->v = other.v;
    }
    return *this;
}
