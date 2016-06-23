#ifndef EXCEPTIONTEST_H
#define EXCEPTIONTEST_H
#include <exception>
#include <string>

namespace yao{
    namespace exception_ex{
        class UserException;
        class NonExceptTest;
        void test();
    }
}

class yao::exception_ex::UserException : public std::exception{
protected:
    std::string _what;
public:
    UserException(std::string _what) : _what(_what){}
    const char* what() const noexcept {return _what.c_str();}
    ~UserException() throw(){}
};

class yao::exception_ex::NonExceptTest
{
public:
    NonExceptTest();
    //If a function is declared as noexcept, and if it throw an exception, this application will be terminated even catch block is written in the caller.
    void noexceptTest() const noexcept;
    void exceptionThrowableTest() const;
};


#endif // EXCEPTIONTEST_H
