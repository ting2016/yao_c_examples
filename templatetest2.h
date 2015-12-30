#ifndef _TESTTEMP_H_
#define _TESTTEMP_H_
template<class T>
class TemplateTest2
{
public:
    TemplateTest2();
    void SetValue( T obj_i );
    T Getalue();
    static void test();

private:
    T m_Obj;
};

#include "templatetest2.inc"
#endif
