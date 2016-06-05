#include "maptest.h"
#include <map>
#include <iostream>

MapKeyClass1::MapKeyClass1(int v):value(v){

}

std::ostream& operator<<(std::ostream& os, const MapKeyClass1& obj){
    return os << obj.value;
}

bool MapKeyClass2::operator<(const MapKeyClass2& obj)const
{
    return (this->value < obj.value);
}


std::ostream& operator<<(std::ostream& os, const MapKeyClass2& obj){
    return os << obj.value;
}

void testMapKey(){
    std::map<MapKeyClass2, int> map;
    MapKeyClass2 k1(1);
    MapKeyClass2 k2(2);
    MapKeyClass2 k3(3);
    map[k1] = 100;
    map[k2] = 200;
    map[k3] = 300;
    for(const auto& x: map)    {
        std::cout << x.first << "\t" << x.second << std::endl;
    }

    std::cout << "----------------------" << std::endl;
    std::map<MapKeyClass1, int, KeyClassCompare> map2;
    MapKeyClass1 k_1(11);
    MapKeyClass1 k_2(22);
    MapKeyClass1 k_3(33);
    map2[k_1] = 1000;
    map2[k_2] = 2000;
    map2[k_3] = 3000;
    for(const auto& x: map2)    {
        std::cout << x.first << "\t" << x.second << std::endl;
    }
}
