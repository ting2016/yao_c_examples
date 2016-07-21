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

void yao::thread_ex::foo1(){
    for(auto i = 0; i < 5; i++){
        std::cout << std::this_thread::get_id () << " is running..." << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
}

void yao::thread_ex::foo2(int v){ //make a copy of para
    for(auto i = 0; i < 5; i++){
        std::cout << std::this_thread::get_id () << " change value to:" << ++v << " is running..." << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
}

void yao::thread_ex::foo3(const int& v){ //make a copy of para as const for default calling; make a real const reference for std::ref(para) calling
    for(auto i = 0; i < 5; i++){
        std::cout << std::this_thread::get_id () << " value:" << v << " is running..." << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
}

void yao::thread_ex::foo4(int& v){ //Not support default calling; make a real reference for std::ref(para) calling
    for(auto i = 0; i < 5; i++){
        std::cout << std::this_thread::get_id () << " change value to:" << ++v << " is running..." << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
}

void yao::thread_ex::foo5(std::string& v){ //Not support default calling; make a real reference for std::ref(para) calling
    for(auto i = 0; i < 5; i++){
        std::cout << std::this_thread::get_id () << " append '*' :" << v.append ("*") << " is running..." << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
}

void yao::thread_ex::testSimpleThread(){
    std::thread job(foo1);
    std::cout << "waiting for thread:" << job.get_id ()<< " to finish its job..." << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(3));
    job.join ();    //if no join and no detach, then on exit: terminate called without an active exception Aborted (core dumped)
}

//NOTE: about passing parameter to a thread handle function
// 1. by default parameter(s) is passing by value(copied). example: void foo(int) == void foo(const int&). void foo(int&) is ill-formated
// 2. if real ref is required, pass std::ref(v) from caller, and the callee should take reference or const reference as parameter. example: void bar(const int&) or void bar(int&)

void yao::thread_ex::testSimpleThreadWithPara(){
    std::string s = "1";
    std::thread job(foo5, std::ref(s));    //make a reference in foo4. fully share data between threads.
    std::this_thread::sleep_for (std::chrono::seconds(2));
    std::cout << "append [c] in caller thread:" << s.append ("c") << std::endl;
    job.join ();
    std::cout << "value in caller thread:" << s << std::endl;
    std::cout << "-----------------" << std::endl;

    int v = 0;
    std::thread job1(foo2, v);   //make a copy
    std::this_thread::sleep_for (std::chrono::seconds(3));
    std::cout << "value in caller thread:" << v << std::endl;
    job1.join ();
    std::cout << "-----------------" << std::endl;

    v= 0;
    std::thread job2(foo3, v);   //make a copy
    std::this_thread::sleep_for (std::chrono::seconds(3));
    std::cout << "increase value in caller thread:" << ++v << std::endl;
    job2.join ();
    std::cout << "-----------------" << std::endl;

    v = 0;
    std::thread job3(foo2, std::ref(v));    //make a copy because foo2 does not take ref as para
    std::this_thread::sleep_for (std::chrono::seconds(3));
    std::cout << "increase value in caller thread:" << ++v << std::endl;
    job3.join ();
    std::cout << "-----------------" << std::endl;

    v = 0;
    std::thread job4(foo3, std::ref(v));    //make a const reference in foo3
    std::this_thread::sleep_for (std::chrono::seconds(3));
    std::cout << "increase value in caller thread:" << ++v << std::endl;
    job4.join ();
    std::cout << "-----------------" << std::endl;

    v = 0;
    std::thread job5(foo4, std::ref(v));    //make a reference in foo4. fully share data between threads.
    std::this_thread::sleep_for (std::chrono::seconds(3));
    std::cout << "increase value in caller thread:" << ++v << std::endl;
    job5.join ();
    std::cout << "-----------------" << std::endl;

    //WARNING std::thread job6(foo4, v);    //ill-formated because we cannot pass reference directly to a thread handle function.
}

/*
 * if a thread is detached, then the thread may continue running long after the std::thread object is destroyed.
 */

void yao::thread_ex::testRunAfterObjectDestroyedOnDetachedThread(){
    {
        std::thread job(foo1);
        job.detach ();
    }

    std::cout << "job is destoyed, yet the thread still running..." << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(3));
}

void yao::thread_ex::testThreadGuard(){
    std::thread job(foo1);
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
    std::thread(&Task::foo, &task).join ();
    std::cout << "------------" << std::endl;

    //method 5: member function as the entrie of a thread
    std::thread(std::bind(&Task::foo, &task)).join ();
    std::cout << "------------" << std::endl;

    //method 6: create object, pass it as a parameter to a thread (deeply, thread take this object reference, then use its functor as the entrie of thread)
    Task task2(0);
    std::thread job6(std::ref(task2));
    std::cout << "waiting for thread:" << job1.get_id ()<< " to finish its job..." << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(3));
    job6.join ();
    std::cout << "------------" << std::endl;
}

void yao::thread_ex::test (){
    //testObjectThread ();
    std::thread t(foo1);
    std::cout << t.get_id () << "\t" << t.joinable () << std::endl;
    t.detach ();
    std::cout << t.get_id () << "\t" << t.joinable () << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
}
