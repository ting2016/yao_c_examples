#include "version.h"
#include <iostream>
const std::string Version::version(){
    std::stringstream s;
    s << "VERSION: " << __DATE__ << " " << __TIME__;
    return s.str();
}

void testVersion(){
    std::cout << Version::version() << std::endl;
}
