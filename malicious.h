#ifndef MALICIOUS_H
#define MALICIOUS_H
#include <exception>
#include <string>
#include <iostream>     // std::cout
#include <iterator>     // std::iterator, std::input_iterator_tag

class YaoException : public std::exception{
protected:
    std::string _what;
public:
    YaoException(std::string _what) : _what(_what){}
    const char* what() const noexcept {return _what.c_str();}
    ~YaoException() throw(){}
};


class MyIterator : public std::iterator<std::input_iterator_tag, int>
{
  int* p;
public:
  MyIterator(int* x) :p(x) {}
  MyIterator(const MyIterator& mit) : p(mit.p) {}
  MyIterator& operator++() {++p;return *this;}
  MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
  bool operator==(const MyIterator& rhs) {return p==rhs.p;}
  bool operator!=(const MyIterator& rhs) {return p!=rhs.p;}
  int& operator*() {return *p;}
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
