#ifndef TIMERTEST_H
#define TIMERTEST_H

#include <functional>
#include <chrono>
#include <future>
#include <cstdio>
#include "foo.h"
namespace yao{
    namespace timer{
        class Timer
        {
        public:
            template <class callable, class... arguments>
            Timer(int after, bool async, callable&& f, arguments&&... args)
            {
                std::function<typename std::result_of<callable(arguments...)>::type()> task(std::bind(std::forward<callable>(f), std::forward<arguments>(args)...));

                if (async)
                {
                    std::thread([after, task]() {
                        std::this_thread::sleep_for(std::chrono::milliseconds(after));
                        task();
                    }).detach();
                }
                else
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(after));
                    task();
                }
            }

        };

        void task1(void);
        void task2(int a);
        void task3(const yao::Foo& f);
        void test();

        int task4(void);

        typedef void(*FUN)();
//        void simpleTimer(int after, FUN task){
        void simpleTimer(int after, void (*task)(void));
        void simpleTimer2(int after, int (*task)(void));
    }
}


#endif // TIMERTEST_H
