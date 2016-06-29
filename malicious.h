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
    }
}
#endif // MALICIOUS_H
