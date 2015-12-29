#pragma once
#include <iostream>

class OStreamOverride{
    int field1, field2, field3;
public:
    OStreamOverride(int f1, int f2, int f3);
    friend std::ostream& operator<<(std::ostream& os, const OStreamOverride& para);
    static void test();
};
