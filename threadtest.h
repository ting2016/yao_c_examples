#ifndef THREADTEST_H
#define THREADTEST_H
#include <chrono>
#include <thread>
#include <iostream>

//NOTE: QT CONFIG : LIBS += -lpthread
//NOTE: compile:: -lpthread
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
            virtual ~Task(){
                std::cout << "DESCTOR is called" << std::endl;
            }

            void operator()() const;
            void print() const;

            void foo();
        private:
            int value;
        };

        class ThreadGuard{
        public:
            explicit ThreadGuard(std::thread& job): m_job(job){
            }
            ~ThreadGuard(){
                if(m_job.joinable ()){
                    m_job.join ();
                }
            }
            ThreadGuard(const ThreadGuard&) = delete;
            ThreadGuard& operator=(const ThreadGuard&) = delete;
            ThreadGuard(ThreadGuard&&) = delete;
        private:
            std::thread& m_job;
        };

        void foo1();
        void foo2(int v);
        void foo3(const int& v);
        void foo4(int& v);

        void testSimpleThread();
        void testSimpleThreadWithPara();
        void testObjectThread();
//        void testObjectThreadWithPara();
        void testRunAfterObjectDestroyedOnDetachedThread();
        void testThreadGuard();
        void test();

    }
}
#endif // THREADTEST_H
