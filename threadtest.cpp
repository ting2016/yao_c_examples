#include "threadtest.h"


void yao::thread_ex::ThreadClass1::operator()() const{
    for(auto i = 1; i < 10; i++){
        std::cout << __func__ << " will sleep 1 second" << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
}


void yao::thread_ex::thread_work(){
    for(auto i = 1; i < 10; i++){
        std::cout << __func__ << " will sleep 1 second" << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
}


void yao::thread_ex::testThread(){
    std::thread m_thread1(thread_work);
    ThreadClass1 threadObj;
    std::thread m_thread2(threadObj);
    m_thread1.join();
    m_thread2.join();
}
