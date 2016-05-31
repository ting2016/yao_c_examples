#ifndef SINGLETON_H
#define SINGLETON_H
#include <iostream>
#include <string>
class SingletonBase
{
public:
    static SingletonBase& instance();
    static SingletonBase* instancePoint();
    void setId(int id);
    int getId() const;
    virtual void bar();
    virtual ~SingletonBase();
protected:
    SingletonBase();
    SingletonBase& operator=( const SingletonBase& ) = delete;
    SingletonBase( const SingletonBase& other ) = delete;

protected:
    int id;
private:
    std::string className;
};

class SingletonDerived:public SingletonBase{
public:
    static SingletonDerived& instance();
    static SingletonDerived* instancePoint();
    void setValue(int);
    virtual void bar();
protected:
    SingletonDerived();
    virtual ~SingletonDerived();
private:
    int value;
private:
    std::string className;
};

void testSingleton();

#endif // SINGLETON_H
