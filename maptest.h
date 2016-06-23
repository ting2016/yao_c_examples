#ifndef MAPTEST_H
#define MAPTEST_H
#include <iostream>

namespace  yao{
    namespace map_ex{
        class MapKeyClass1;
        class MapKeyClass2;
        struct KeyClassCompare;
        void test();
    }
}

class yao::map_ex::MapKeyClass1{
public:
    MapKeyClass1(int);
private:
    int value;

    friend struct KeyClassCompare;
    friend inline std::ostream& operator<<(std::ostream& os, const MapKeyClass1& obj){
        return os << obj.value;
    }
};


struct yao::map_ex::KeyClassCompare
{
   bool operator() (const MapKeyClass1& lhs, const MapKeyClass1& rhs) const
   {
       return lhs.value < rhs.value;
   }
};

class yao::map_ex::MapKeyClass2
{
public:
    MapKeyClass2(int v): value(v){}
    bool operator<(const MapKeyClass2& obj) const;

private:
    int value;

    friend inline std::ostream& operator<<(std::ostream& os, const MapKeyClass2& obj){
        return os << obj.value;
    }
};


#endif // MAPTEST_H
