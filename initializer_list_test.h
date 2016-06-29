#ifndef INITIALIZER_LIST_TEST_H
#define INITIALIZER_LIST_TEST_H
#include <initializer_list>
namespace yao{
    namespace initializer_list{
        template <typename T>
        class Foo {
        public:
            Foo(std::initializer_list<int> args) {
                m_size = args.size ();
                if(m_size > 0){
                    m_data = new T [m_size];
                    int i = 0;
                    for (auto& t : args) {
                        m_data[i++] = t;
                    }
                }else{
                    m_data = nullptr;
                }
            }

            ~Foo(){
                if(m_size){
                    delete []m_data;
                }
            }

            T* begin() {return m_data;}
            T* end() {return m_data+m_size;}

            T* m_data;
            unsigned m_size;
        };

        void test();
    }
}

#endif // INITIALIZER_LIST_TEST_H
