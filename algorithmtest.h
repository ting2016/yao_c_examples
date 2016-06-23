#ifndef ALGORITHMTEST_H
#define ALGORITHMTEST_H
namespace yao{
    namespace algorithm{
        class Algorithm;
        void algoOutput(int i);
        void algoIncreace(int& i);
        void test();

        class Algorithm
        {
        public:
            void operator()(int&) const;
        };
    }
}

#endif // ALGORITHMTEST_H
