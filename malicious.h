#ifndef MALICIOUS_H
#define MALICIOUS_H
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
    }
}
#endif // MALICIOUS_H
