#ifndef PURETEST_H
#define PURETEST_H
namespace yao{
    namespace ctor_ex{
        class Foo{
        public:
            Foo();
            Foo(int m_size);
            Foo(const Foo& other);
            Foo& operator ()();
            Foo& operator =(const Foo& other);
            Foo(Foo&& other);
            Foo& operator =(Foo&& other);
            ~Foo();
            void print() const;
        private:
            int m_size;
            int m_capacity;
            int* m_data;
        };

        void test();
        void test_move_ctor(Foo&& f);
        void test_move_ctor(Foo& f);
    }
}


#endif // PURETEST_H
