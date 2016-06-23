#include "hashtest.h"
#include <hashtest.h>
#include <iostream>
#include <unordered_map>

yao::hash_ex::HashKeyClass::HashKeyClass(const std::string& name, int age, bool gender)
    : name(name)
    , age(age)
    , gender(gender){
}

bool yao::hash_ex::HashKeyClass::operator()(const HashKeyClass& a, const HashKeyClass& b) const {
    if(&a == &b)
        return true;

    if(a.name != b.name)
        return false;

    if(a.age != b.age)
        return false;

    if(a.gender != b.gender)
        return false;

    return true;
}

bool yao::hash_ex::HashKeyClass::operator==(const HashKeyClass& b) const{
    if(this == &b)
        return true;

    if(name != b.name)
        return false;

    if(age != b.age)
        return false;

    if(gender != b.gender)
        return false;

    return true;
}



std::size_t yao::hash_ex::HashKeyClass::hashId() const{
//    std::hash<std::string> ptr_hash;
//    std::cout << ptr_hash(name) << std::endl;
//    std::cout << std::hash<std::string>()(name) << std::endl;
//    std::cout << std::hash<std::string>{}(name) << std::endl;
//    std::size_t const h (std::hash<std::string>()(name));
//    std::cout << h << std::endl;

    std::size_t const h1 = std::hash<std::string>()(name);
    std::size_t const h2 = std::hash<int>()(age);
    std::size_t const h3 = std::hash<bool>()(gender);

    return h1 ^ (h2 << 1) ^ (h3 << 2);
}




std::size_t std::hash<yao::hash_ex::HashKeyClass>::operator()(yao::hash_ex::HashKeyClass const& s) const{
    auto h1 = std::hash<std::string>()(s.name);
    auto h2 = std::hash<int>()(s.age);
    auto h3 = std::hash<bool>()(s.gender);
    return h1 ^ (h2 << 1) ^ (h3 << 2);
}


void yao::hash_ex::testHash(){
    HashKeyClass obj1("zhangsan", 22, true);
    HashKeyClass obj2("lisi", 23, false);
    std::unordered_map<std::string, HashKeyClass> map1;
    map1[obj1.name] = obj1;
    map1[obj2.name] = obj2;


    for(const auto& x: map1){
        std::cout << x.first << "\t" << x.second << std::endl;
    }

    std::cout << "----------------------" << std::endl;

    std::unordered_map<HashKeyClass, int> map2;
    map2[obj1] = obj1.age;
    map2[obj2] = obj2.age;

    for(const auto& x: map2){
        std::cout << x.first << "\t" << x.second << std::endl;
    }
}
