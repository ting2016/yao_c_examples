#include "version.h"
#include <iostream>
const std::string yao::version::VersionGenerator::version(){
    std::stringstream s;
    s << "VERSION:" << __DATE__ << "_" << __TIME__;
    return s.str();
}

void yao::version::test(){
    std::cout << VersionGenerator::version() << std::endl;
}
