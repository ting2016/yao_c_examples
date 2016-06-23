#ifndef YAOSTL_H
#define YAOSTL_H
#include <iterator>
#include <cassert>
#include <iostream>
#include <algorithm>
namespace yao{
    namespace stl{
        template <typename T>
        class SimpleVector;
        template <typename T>
        class SimpleArray;
    }
}


template <typename T>
class yao::stl::SimpleVector{
public:
    class iterator
    {
    public:
        iterator() = delete;
        iterator(T** ptr) : m_ptr(ptr){ }
        iterator operator++() { iterator i(*this); m_ptr++; return i; }
//        iterator operator++() { iterator i = *this; m_ptr++; return i; }
        iterator operator++(int) { m_ptr++; return *this; }
        iterator (const iterator & other){this->m_ptr = other.m_ptr;}

        T& operator*() { return **m_ptr; }
        T* operator->() { return *m_ptr; }
        bool operator==(const iterator& rhs) { return m_ptr == rhs.m_ptr; }
        bool operator!=(const iterator& rhs) { return m_ptr != rhs.m_ptr; }
    private:
        T** m_ptr;
    };

    SimpleVector();
    SimpleVector(int size);
    ~SimpleVector();
    inline T& operator[](int index);
    inline int size() const { return m_size; }
    inline iterator begin(){return iterator(m_data);}
    inline iterator end(){return iterator(m_data + m_size);}
    inline void push_back(const T& e);
    inline void resize();

private:

protected:
    T** m_data;
    int m_size;
    int m_capacity;
};

template <typename T>
yao::stl::SimpleVector<T>::SimpleVector()
    : SimpleVector(0){
}


template <typename T>
inline T& yao::stl::SimpleVector<T>::operator[](int index){
    assert(index < m_size);
    return *m_data[index];
}

template <typename T>
yao::stl::SimpleVector<T>::~SimpleVector(){
    for(auto i = 0; i < m_size; i++){
        delete m_data[i];
    }
    delete m_data;
}

template <typename T>
yao::stl::SimpleVector<T>::SimpleVector(int size) : m_size(size) {
    assert(size >= 0);
    m_capacity = m_size * 2 + 1;
    m_data = new T*[m_capacity];
}

template <typename T>
inline void yao::stl::SimpleVector<T>::resize(){
    //    std::cout << "before resize, m_capacity:" << m_capacity << std::endl;
    m_capacity *= 2;
    T** t = new T*[m_capacity];
    std::copy(m_data, m_data + m_size, t);
    delete m_data;
    m_data = t;
}

template <typename T>
inline void yao::stl::SimpleVector<T>::push_back(const T& e){
    if(m_size > m_capacity){
        resize ();
    }

    T* t = new T(e);
    m_data[m_size++] = t;
}



template <typename T>
class yao::stl::SimpleArray
{
    public:
        typedef int size_type;
        class mm_iter
        {
            public:
                typedef mm_iter self_type;
                typedef T value_type;
                typedef T& reference;
                typedef T* pointer;
                typedef std::forward_iterator_tag iterator_category;
                typedef int difference_type;
                mm_iter(pointer ptr) : ptr_(ptr) { }
                self_type operator++() { self_type i = *this; ptr_++; return i; }
                self_type operator++(int junk) { ptr_++; return *this; }
                reference operator*() { return *ptr_; }
                pointer operator->() { return ptr_; }
                bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
                bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
            private:
                pointer ptr_;
        };

        class const_iterator
        {
            public:
                typedef const_iterator self_type;
                typedef T value_type;
                typedef T& reference;
                typedef T* pointer;
                typedef int difference_type;
                typedef std::forward_iterator_tag iterator_category;
                const_iterator(pointer ptr) : ptr_(ptr) { }
                self_type operator++() { self_type i = *this; ptr_++; return i; }
                self_type operator++(int) { ptr_++; return *this; }
                const reference operator*() { return *ptr_; }
                const reference operator->() { return ptr_; }
                bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
                bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
            private:
                pointer ptr_;
        };

        T& operator[](size_type index)
        {
            assert(index < size_);
            return data_[index];
        }

        SimpleArray(size_type size) : size_(size) {
            data_ = new T[size_];
        }

        size_type size() const { return size_; }



        const T& operator[](size_type index) const
        {
            assert(index < size_);
            return data_[index];
        }

        mm_iter begin()
        {
            return mm_iter(data_);
        }

        mm_iter end()
        {
            return mm_iter(data_ + size_);
        }

        const_iterator begin() const
        {
            return const_iterator(data_);
        }

        const_iterator end() const
        {
            return const_iterator(data_ + size_);
        }

    private:
        T* data_;
        size_type size_;
};

void testYaoStl();

#endif // YAOSTL_H
