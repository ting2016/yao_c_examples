#ifndef HASH_H
#define HASH_H
#include <string>
#include <iostream>

namespace yao{
    namespace hash_ex {
        class HashKeyClass;
        void testHash();
    }
}
class yao::hash_ex::HashKeyClass{
private:
    std::string name;
    int age;
    bool gender;
public:
    HashKeyClass(){}
    HashKeyClass(const std::string& name, int age, bool gender);
    bool operator()(const HashKeyClass& a, const HashKeyClass& b) const;
    bool operator==(const HashKeyClass& b) const;
    std::size_t hashId() const;
    friend inline std::ostream& operator<<(std::ostream& os, const HashKeyClass& obj){
        return os << obj.name << ", " << obj.age;
    }

    friend struct std::hash<HashKeyClass>;
    friend void testHash();
};


namespace std
{
    template<> struct hash<yao::hash_ex::HashKeyClass>
    {
        std::size_t operator()(yao::hash_ex::HashKeyClass const& s) const;
    };

    //    template<> struct hash<HashKeyClass>
    //    {
    //        std::size_t operator()(HashKeyClass const& s) const
    //        {
    //            auto h1 = std::hash<std::string>()(s.name);
    //            auto h2 = std::hash<int>()(s.age);
    //            return h1 ^ (h2 << 1); // or use boost::hash_combine
    //        }
    //    };
}


#endif // HASH_H
