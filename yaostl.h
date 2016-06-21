#ifndef YAOSTL_H
#define YAOSTL_H
#include <iterator>
#include <cassert>
namespace yaostl{
template <typename T>
class SimpleVector;
}


template <typename T>
class yaostl::SimpleVector{
public:
    typedef int size_type;
    class iterator
    {
        public:
            typedef iterator self_type;
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef int difference_type;
            iterator(pointer ptr) : m_ptr(ptr) { }
            self_type operator++() { self_type i = *this; m_ptr++; return i; }
            self_type operator++(int junk) { m_ptr++; return *this; }
            reference operator*() { return *m_ptr; }
            pointer operator->() { return m_ptr; }
            bool operator==(const self_type& rhs) { return m_ptr == rhs.m_ptr; }
            bool operator!=(const self_type& rhs) { return m_ptr != rhs.m_ptr; }
            private:
            pointer m_ptr;
    };

    SimpleVector();
    SimpleVector(size_type size);
    ~SimpleVector();
    inline T& operator[](size_type index);
    inline size_type size() const { return m_size; }
    inline iterator begin(){return iterator(m_data);}
    inline iterator end(){return iterator(m_data + m_size);}
    inline void push_back(const T& e){
        if(m_size == m_capacity){
            m_capacity = m_size * 2 + 1;
            T* tmp_data = new T[m_capacity];
            std::copy(m_data, m_data + m_size, tmp_data);
            if(m_size > 0){
                delete[]m_data;
            }
            m_data = tmp_data;
        }
        end() = new T(e);
    }

protected:
    T* m_data;
    size_type m_size;
    size_type m_capacity;
};

template <typename T>
yaostl::SimpleVector<T>::SimpleVector()
    : SimpleVector(0){
}


template <typename T>
inline T& yaostl::SimpleVector<T>::operator[](size_type index){
    assert(index < m_size);
    return m_data[index];
}

template <typename T>
yaostl::SimpleVector<T>::~SimpleVector(){
    if(m_size > 0){
        delete []m_data;
    }
}

template <typename T>
yaostl::SimpleVector<T>::SimpleVector(size_type size) : m_size(size) {
    assert(size >= 0);
    m_capacity = m_size * 2 + 1;
    m_data = new T[m_size];
}
void testYaoStl();

#endif // YAOSTL_H
