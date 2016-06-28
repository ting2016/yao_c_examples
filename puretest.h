#ifndef PURETEST_H
#define PURETEST_H
namespace yao{
    namespace puretest{
        class Foo{
        public:
            Foo();
            Foo(int v);
            Foo(const Foo& other);
            Foo& operator ()();
            Foo& operator =(const Foo& other);
            Foo(Foo&& other);
            Foo& operator =(Foo&& other);
            ~Foo();
            void bar() const;
//        private:
            int v;
        };

        void test();
        void test2(Foo&& f);
        void test2(Foo& f);
    }
}
#endif // PURETEST_H
