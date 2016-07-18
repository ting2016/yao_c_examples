#ifndef THREADTEST_H
#define THREADTEST_H
#include <chrono>
#include <thread>
#include <iostream>
namespace yao{
    namespace thread_ex{
        class ThreadClass1
        {
        public:
            ThreadClass1(){}
            void operator()() const;
        };

        void thread_work();
        void testThread();

    }
}


#endif // THREADTEST_H
