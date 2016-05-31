#ifndef SINGLETON_H
#define SINGLETON_H
#include <iostream>

class Singleton
{
private:
    Singleton();
    ~Singleton();
    int v;
public:
    void setValue(int v);
    int getValue() const;
    static Singleton& instance();
};

void testSingleton();

#endif // SINGLETON_H
