#ifndef FUNCTORTEST_H
#define FUNCTORTEST_H

#include <iostream>
class myFunctorClass
{
    public:
        myFunctorClass (int x) : _x( x ) {}
        int operator() (int y) { return _x + y; }
    private:
        int _x;
};

void testFunctor();

#endif // FUNCTORTEST_H
