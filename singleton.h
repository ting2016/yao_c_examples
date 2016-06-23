#ifndef SINGLETON_H
#define SINGLETON_H
#include <string>
namespace yao{
    namespace singleton{
        class SingletonBase;
        class SingletonDerived;
        void test();
    }
}
class yao::singleton::SingletonBase
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

class yao::singleton::SingletonDerived:public yao::singleton::SingletonBase{
public:
    static SingletonDerived& instance();
    static SingletonDerived* instancePoint();
    void setValue(int);
    virtual void bar();
protected:
    SingletonDerived();
    SingletonDerived& operator=( const SingletonDerived& ) = delete;
    SingletonDerived( const SingletonDerived& other ) = delete;
    virtual ~SingletonDerived();
private:
    int value;
private:
    std::string className;
};


#endif // SINGLETON_H
