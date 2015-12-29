#pragma once
template <class T>
class TemplateTest {
private:
    T a, b;
public:
    TemplateTest(T first, T second){
        a=first;
        b=second;
    }

    T getmax(){
        T retval;
        retval = a>b? a : b;
        return retval;
    }

    //    static void test(T t);
};


