#include "signaltest.h"
#include <unistd.h>
#include <signal.h>
#include <iostream>

void yao::signalTset::signalHandler(int sig){
    std::cout << "alarm signal received" << std::endl;
    alarm (3);
    std::cout << "emit an alarm signal" << std::endl;
}

void yao::signalTset::testSignal (){

    signal(SIGALRM, signalHandler);
    alarm(3);

    for(auto i = 0; i < 10; i++){
        std::cout << " loop " << i << std::endl;
        sleep(1);
    }
}
