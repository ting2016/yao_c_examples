#ifndef YAOSTL_H
#define YAOSTL_H
#include <iterator>
#include <cassert>
#include <iostream>
namespace yaostl{
template <typename T>
class SimpleVector;
}


template <typename T>
class yaostl::SimpleVector{
public:
    class iterator
    {
        public:
            iterator(T* ptr) : m_ptr(ptr) { }
            iterator operator++() { iterator i = *this; m_ptr = *(&m_ptr + 1); return i; }
            iterator operator++(int) { m_ptr = *(&m_ptr + 1); return *this; }
            T& operator*() { return *m_ptr; }
            T* operator->() { return m_ptr; }
            bool operator==(const iterator& rhs) { return m_ptr == rhs.m_ptr; }
            bool operator!=(const iterator& rhs) { return m_ptr != rhs.m_ptr; }
            private:
            T* m_ptr;
    };

    SimpleVector();
    SimpleVector(int size);
    ~SimpleVector();
    inline T& operator[](int index);
    inline int size() const { return m_size; }
    inline iterator begin(){return iterator(*m_data);}
    inline iterator end(){return iterator(*(m_data + m_size));}
    inline void push_back(const T& e){
        std::cout << __func__ << " vector size: " << m_size << std::endl;
        if(m_size > m_capacity){
            resize ();
        }

        T* t = new T(e);
        std::cout << __func__ << " add element(addr):" << t << " to position: " << m_size + 1 << std::endl;
        m_data[m_size++] = t;
    }

    void print(){
        for(auto i = 0; i < m_size; i++){
            std::cout << "element " << i << " addr: " << m_data[i] << "elem:" << *m_data[i] << std::endl;
        }
    }

    inline void resize();
private:

protected:
    T** m_data;
    int m_size;
    int m_capacity;
};

template <typename T>
yaostl::SimpleVector<T>::SimpleVector()
    : SimpleVector(0){
}


template <typename T>
inline T& yaostl::SimpleVector<T>::operator[](int index){
    assert(index < m_size);
    return *m_data[index];
}

template <typename T>
yaostl::SimpleVector<T>::~SimpleVector(){
    for(auto i = 0; i < m_size; i++){
        delete m_data[i];
    }
    delete m_data;
}

template <typename T>
yaostl::SimpleVector<T>::SimpleVector(int size) : m_size(size) {
    assert(size >= 0);
    m_capacity = m_size * 2 + 1;
    m_data = new T*[m_capacity];
}

template <typename T>
inline void yaostl::SimpleVector<T>::resize(){
    std::cout << "before resize, m_capacity:" << m_capacity << std::endl;
    m_capacity *= 2;
    T** t = new T*[m_capacity];
    std::copy(m_data, m_data + m_size, t);
    delete m_data;
    m_data = t;
}

void testYaoStl();

#endif // YAOSTL_H
