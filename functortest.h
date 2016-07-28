#ifndef FUNCTORTEST_H
#define FUNCTORTEST_H
#include <string>
#include <iostream>
namespace yao{
    namespace functor_ex{

        class Functor
        {
        public:
            Functor (int x) : _x( x ) {}
            int operator() (int y) { return _x + y; }
        private:
            int _x;
        };



        class Functor2 {
        public:
            Functor2()
                : Functor2(0){

            }

            Functor2(const int v)
                : v(v){

            }

            operator int(){
                std::cout << "--->int\t";
                return v;
            }
            operator double(){
                std::cout << "---> double\t";
                return v;
            }

            operator std::string(){
                std::cout << "---> string\t";
                return std::to_string (v);
            }

        private:
            int v;
        };

        void test();
    }
}


#endif // FUNCTORTEST_H
