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

        // a function:
        int half(int x);

        // a function object class:
        struct third_t {
          int operator()(int x) {return x/3;}
        };

        // a class with data members:
        struct MyValue {
          int value;
          int fifth() {return value/5;}
        };

    }
}

#endif // FUNCTIONALTEST_H
