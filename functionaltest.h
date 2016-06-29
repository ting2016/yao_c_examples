#ifndef FUNCTIONALTEST_H
#define FUNCTIONALTEST_H
namespace yao{
    namespace functional{
        typedef struct{
            double a,b;
            double multiply() {return a*b;}
        }Pair;
        void test();
        double my_divide (double x, double y);
    }
}

#endif // FUNCTIONALTEST_H
