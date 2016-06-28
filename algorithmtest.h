#ifndef ALGORITHMTEST_H
#define ALGORITHMTEST_H
namespace yao{
    namespace algorithm{
        class Algorithm;
        void algoOutput(int i);
        void algoIncreace(int& i);
        void test();
        bool less_0_predicate(const int& v);
        bool equal_predicate(const int& v1, const int& v2);

        void mem_test();
        class Algorithm
        {
        public:
            void operator()(int&) const;
        };
    }
}

#endif // ALGORITHMTEST_H
