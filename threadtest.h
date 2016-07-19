#ifndef THREADTEST_H
#define THREADTEST_H
#include <chrono>
#include <thread>
#include <iostream>

namespace yao{
    namespace thread_ex{

        class Task{
        public:
            Task():Task(0){
                std::cout << "Default CTOR is called" << std::endl;
            }
            Task(int v): value(v){
                std::cout << "CTOR(int) is called" << std::endl;
            }
            Task(const Task& other){
                std::cout << "Copy CTOR is called" << std::endl;
                this->value = other.value;
            }

            Task(const Task&& other){
                std::cout << "Move CTOR is called" << std::endl;

                this->value = other.value;
            }

            Task& operator =(const Task& other){
                std::cout << "Assign CTOR is called" << std::endl;
                if(&other != this){
                    this->value = other.value;
                }
                return *this;
            }

            void operator()() const;
            void print() const;

        private:
            int value;
        };

        void foo();


        void testSimpleThread();
        void testObjectThread();
        void testRunAfterObjectDestroyedOnDetachedThread();
        void test();

    }
}


#endif // THREADTEST_H
