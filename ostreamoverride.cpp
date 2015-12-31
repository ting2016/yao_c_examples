#include <iostream>
#include "ostreamoverride.h"
OStreamOverride::OStreamOverride(int f1, int f2, int f3){
    field1 = f1; field2 = f2; field3 = f3;
}

std::ostream& operator<<(std::ostream& os, const OStreamOverride& para){
    os << para.field1 << '-' << para.field2 << '-' << para.field3;
    return os;
}


void testOStreamOverride(){
    OStreamOverride oso(31, 12, 2015);
    std::cout << oso << std::endl;
}
