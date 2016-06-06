#ifndef _TEMPLATETEST2_
#define _TEMPLATETEST2_
template<class T>
class TemplateTest2{
public:
    TemplateTest2();
    void SetValue( T obj_i );
    T Getalue();

private:
    T m_Obj;
};

void testTemplate2();
#include "templatetest2.inc"
#endif
