#ifndef FUNCTORTEST_H
#define FUNCTORTEST_H

#include <iostream>
namespace yao{
    namespace functor_ex{
        class Functor;
        void test();
    }
}
class yao::functor_ex::Functor
{
    public:
        Functor (int x) : _x( x ) {}
        int operator() (int y) { return _x + y; }
    private:
        int _x;
};


#endif // FUNCTORTEST_H
