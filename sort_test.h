#ifndef SORT_TEST_H
#define SORT_TEST_H
#include <iostream>
#include <chrono>
#include <random>
namespace yao{
    int generateRandomNumber(int start, int end);
    template <typename T>
    class Comparator{
    public:
        Comparator(bool asc)
            : asc(asc){
        }

        bool operator()(const T& e1, const T& e2) const{
            if(asc){
                return e1 < e2;
            }else{
                return e1 > e2;
            }
        }
    private:
        bool asc;
    };

    template <typename T>
    void exchange(T& e1, T& e2){
        T t = e1;
        e1 = e2;
        e2 = t;
    }

    template <typename T>
    void heapify(T* A, const int& size, const int& i, const Comparator<T>& cmp){
        if(size < 2){
            return ;
        }

        if((i + 1) * 2 > size){
            return;
        }

        auto l = 2 * i + 1;
        auto r = 2 * i + 2;
        auto larger = i;
        if(cmp(A[l], A[i])){
            larger = l;
        }

        if(r < size && cmp(A[r], A[larger])){
            larger = r;
        }

        if(larger != i){
            exchange(A[i], A[larger]);
            heapify(A, size, larger, cmp);
        }

    }

    template <typename T>
    void buildHeap(T* A, const int& size, const Comparator<T>& cmp){
        auto half = size / 2 -1;
        for(auto i = half; i > -1; i--){
            heapify(A, size, i, cmp);
        }
    }

    template <typename T>
    void heapsort(T* A, int size, bool asc = true){
        Comparator<T> cmp(asc);
        buildHeap(A, size, cmp);

        for(auto i = size - 1; i > 0; i--){
            exchange(A[i], A[0]);
            heapify(A, i, 0, cmp);
        }
    }

    template <typename T>
    int partition(T* A, const int start, const int end, const Comparator<T>& cmp){
        auto randPivot = generateRandomNumber(start, end);
        exchange(A[randPivot], A[end]);
        auto i = start - 1;
        for(auto j = start; j < end; j++){
            if(cmp(A[j], A[end])){
                exchange(A[++i], A[j]);
            }
        }
        exchange(A[i + 1], A[end]);
        return i + 1;
    }

    template <typename T>
    void quicksort(T* A, int start, int end, bool asc = true){
        Comparator<T> cmp(asc);
        if(start < end){
            auto pivot = partition(A, start, end, cmp);
            quicksort(A, start, pivot - 1, asc);
            quicksort(A, pivot + 1, end, asc);
        }
    }

    enum PrioryQueueType{
        MIN = 0,
        MAX = 1
    };

    template <typename T>
    class PrioryQueue{
    public:
        PrioryQueue(PrioryQueueType type = MIN)
            : type(type){

        }

        const T& first() const /*throw exception*/{

        }

        const T extract() /*throw exception*/{

        }

        void heapify(){

        }

        void changekey(){

        }

        void insert(const T& e){

        }

    private:
        std::vector<T> m_data;
        PrioryQueueType type;
    };
}

#endif // SORT_TEST_H
