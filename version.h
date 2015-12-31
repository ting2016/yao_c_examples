#ifndef VERSION_H
#define VERSION_H
#include <iostream>
inline void printVersion(){
    std::cout << "VERSION: " << __DATE__ << " " << __TIME__ << std::endl;
}

#endif // VERSION_H
