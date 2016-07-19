#include "threadtest.h"
#include <functional>
void yao::thread_ex::Task::print() const{
    std::cout << "value:" << value << std::endl;
}

void yao::thread_ex::Task::operator()() const{
    for(auto i = 0; i < 5; i++){
        std::cout << std::this_thread::get_id () << " is running..." << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
}

void yao::thread_ex::Task::foo(){
    for(auto i = 0; i < 5; i++){
        std::cout << std::this_thread::get_id () << " is running..." << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
}

void yao::thread_ex::foo(){
    for(auto i = 0; i < 5; i++){
        std::cout << std::this_thread::get_id () << " is running..." << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
}


void yao::thread_ex::testSimpleThread(){
    std::thread job(foo);
    std::cout << "waiting for thread:" << job.get_id ()<< " to finish its job..." << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(3));
    job.join ();    //if no join and no detach, then on exit: terminate called without an active exception Aborted (core dumped)
}

/*
 * if a thread is detached, then the thread may continue running long after the std::thread object is destroyed.
 */

void yao::thread_ex::testRunAfterObjectDestroyedOnDetachedThread(){
    {
        std::thread job(foo);
        job.detach ();
    }

    std::cout << "job is destoyed, yet the thread still running..." << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(3));
}

void yao::thread_ex::testThreadGuard(){
    std::thread job(foo);
    ThreadGuard g(job);
}

/*
 * 1. functor must be defined
 * 2. thread will make a copy of this object
 * 3. detach or join is demanded otherwise segmentation fault will occur
 * 4. once a thread finished, its thread_id is expired
 * 5. detached thread's thread_id is not valid
 * 6. once a thread is detached or joined, its joinable is false
 */
void yao::thread_ex::testObjectThread(){
    //method 1: create object, pass it as parameter to a thread (deeply: thread take object as parameter, then make a copy, then use the copy's functor as the entrie of thread)
    Task task(10);
    std::thread job1(task);
    std::cout << "waiting for thread:" << job1.get_id ()<< " to finish its job..." << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(3));
    job1.join ();

    std::cout << "------------" << std::endl;
    //method 2:
    //std::thread job2((Task()));
    std::thread job2{(Task())};
    //std::thread job2(Task()); //ill formated
    std::cout << "waiting for thread:" << job2.get_id ()<< " to finish its job..." << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(3));
    job2.join ();
    std::cout << "------------" << std::endl;

    //method 3: ananimous thread and lambda
    std::thread([](){
        for(auto i = 0; i < 5; i++){
            std::cout << std::this_thread::get_id () << " is running..." << std::endl;
            std::this_thread::sleep_for (std::chrono::seconds(1));
        }
    }).join ();

    std::cout << "------------" << std::endl;
    //method 4: member function as the entrie of a thread
    std::thread(std::bind(&Task::foo, &task)).join ();
}

void yao::thread_ex::test (){
    //testObjectThread ();
    std::thread t(foo);
    std::cout << t.get_id () << "\t" << t.joinable () << std::endl;
    t.detach ();
    std::cout << t.get_id () << "\t" << t.joinable () << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
}
