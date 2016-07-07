#include "signaltest.h"
#include <unistd.h>
#include <csignal>
#include <iostream>

void yao::signalTset::signalHandler(int sig){
    if(sig == SIGALRM){
        std::cout << "alarm signal received" << std::endl;
        static int i = 1;
        if(i < 10){
            alarm (1);
            std::cout << "emit an alarm signal" << std::endl;
            i++;
        }
    }else if(sig == SIGINT){
        std::cout << "SIGINT received" << std::endl;
        static int i = 1;
        if(i < 10){
            i++;
            sleep(1);
            raise(SIGINT);
        }

    }else{
        std::cout << "unknown signal:" << sig << std::endl;
    }
}

void yao::signalTset::testSignal (){
    signal(SIGALRM, signalHandler);
    alarm(1);
}


void yao::signalTset::testSignal2 (){
    std::cout <<"SIGRTMIN :" << SIGRTMIN << std::endl;
    std::cout <<"SIGRTMAX :" << SIGRTMAX << std::endl;
    signal (SIGINT, signalHandler);

    raise (SIGINT);
}
