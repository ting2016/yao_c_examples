#pragma once
template <typename T>
class TemplateTest1 {
private:
    T a, b;
public:
    TemplateTest1(T first, T second);
    T getmax();
    static void test();
};


