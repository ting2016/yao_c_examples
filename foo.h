#ifndef FOO_H
#define FOO_H
#include <iostream>
class Foo
{
public:
    Foo();
    Foo(const int& v);
    Foo(const Foo& other);
    Foo& operator =(const Foo& other);
    void bar() const;
    void increaceValue();
    ~Foo();
private:
    int v;
};

#endif // FOO_H
