#include "bar.h"

using namespace yao_bar;

Bar::Bar(const Bar& other){
    this->v = other.v;
}

Bar& Bar::operator = (const Bar& other){
    if(this != &other){
        this->v = other.v;
    }
    return *this;
}

int Bar::getV() const{
    return v;
}

std::ostream& Bar::stream_write(std::ostream& os) const{
    return os << v;
}

inline std::ostream& operator<<(std::ostream& os, const Bar& obj){
    return obj.stream_write(os);
}
