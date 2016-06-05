#ifndef HASH_H
#define HASH_H
#include <string>
#include <iostream>
class HashKeyClass{
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
    friend std::ostream& operator<<(std::ostream& os, const HashKeyClass& para);
    friend struct std::hash<HashKeyClass>;
    friend void testHash();
};

//namespace std
//{
//    template<> struct hash<HashKeyClass>
//    {
//        std::size_t operator()(HashKeyClass const& s) const
//        {
//            auto h1 = std::hash<std::string>()(s.name);
//            auto h2 = std::hash<int>()(s.age);
//            return h1 ^ (h2 << 1); // or use boost::hash_combine
//        }
//    };
//}
namespace std
{
    template<> struct hash<HashKeyClass>
    {
        std::size_t operator()(HashKeyClass const& s) const;
    };
}

void testHash();
#endif // HASH_H
