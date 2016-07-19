#ifndef NAMESPACE_H
#define NAMESPACE_H

//NOTE namespace usage
/*! namespace note
 * Two ways to write namespace
 * 1. put the full declaration in the namespace (preferred! because the details can be show in IDEs' class view, and member functions can be retriewed with some hot key)
 * 2. put the class name in the namespace
 */
namespace yao{
    namespace note{
        //first way
        class TestClass1{
        public:
            void fun1(){}
        protected:
            void fun2(){}
        private:
            void fun3(){}
        };

        //second way
        class TestClass2;
    }
}

class yao::note::TestClass2{
    public:
    void fun1(){}
    protected:
    void fun2(){}
    private:
    void fun3(){}
};

#endif // NAMESPACE_H
