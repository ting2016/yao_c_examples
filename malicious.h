#ifndef MALICIOUS_H
#define MALICIOUS_H
#include <exception>
#include <string>
class YaoException : public std::exception{
protected:
    std::string _what;
public:
    YaoException(std::string _what) : _what(_what){}
    const char* what() const noexcept {return _what.c_str();}
    ~YaoException() throw(){}
};


class Malicious
{
public:
    Malicious();
    //If a function is declared as noexcept, and if it throw an exception, this application will be terminated even catch block is written in the caller.
    void noexceptTest() const noexcept;
    void exceptionThrowableTest() const;

    void testPerformanceOfTraverseVector();
};

void testMalicious();

#endif // MALICIOUS_H
