#ifndef FOO_H
#define FOO_H
#include <iostream>

namespace yao{
class Foo;
}
class yao::Foo
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

    friend std::ostream& operator<<(std::ostream& os, const Foo& obj){
        return os << "foo:" << obj.v;
    }
};






#endif // FOO_H
