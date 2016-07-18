#ifndef MALICIOUS_H
#define MALICIOUS_H
#include <iostream>
#include <iterator>
namespace yao{
    namespace malicious {
        class MyIterator : public std::iterator<std::input_iterator_tag, int>
        {
          int* p;
        public:
          MyIterator(int* x) :p(x) {}
          MyIterator(const MyIterator& mit) : p(mit.p) {}
          MyIterator& operator++() {++p;return *this;}
          MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
          bool operator==(const MyIterator& rhs) {return p==rhs.p;}
          bool operator!=(const MyIterator& rhs) {return p!=rhs.p;}
          int& operator*() {return *p;}
        };

        void test();
        void testPerformanceOfTraverseVector();
        void testVectorTraverse();
        void testIterator();
        void testIOStreamIterator();
        void mem_speed_test();
        void testPair();

        class SomeClass{
        public:
            SomeClass() = delete;
            SomeClass(double v): v(v){}
            auto operator()() const -> int{    //NOTE the result will be casted as int
                return v;
            }

            auto operator()(auto) const -> double{    //NOTE the result will be casted as int
                return v;
            }

            double& operator()(auto, auto) {    //NOTE the result will be casted as int
                return v;
            }

            void print() const{
                std::cout << "SomeClass.v:" << v << std::endl;
            }

        private:
            double v;
        };

        void test_return_auto();


        /*!
         * \brief Once a class is declared as final, it cannot be derived
         * once a method is declared as final, it cannot be overriden
         */
        class Base{
        public:
            virtual void fun() const = 0;
        };

        class Derived0: public Base{
        public:
            virtual /*virtual is optional*/ void fun() const override;
        };

        class Derived1: public Base{
        public:
            virtual /*virtual is optional*/ void fun() const override final;
        };

        class Derived2 final: public Base{
        public:
            virtual /*virtual is optional*/ void fun() const override final;
        };

        class Derived0Derived final: public Derived0{
        public:
            virtual /*virtual is optional*/ void fun() const override final;
        };

        class Derived1Derived final: public Derived1{
        public:
//            void fun() const override final;  //ill format because fun is final in Derived1
        };

        //class Derived2Derived final: public Derived2{}; //ill formated because Derived2 is final class

        void testFinalClassFinalMethod();
        void pureTest();
    }
}
#endif // MALICIOUS_H
