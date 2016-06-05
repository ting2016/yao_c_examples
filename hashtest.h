#ifndef HASH_H
#define HASH_H
#include <string>
#include <iostream>
class HashObject{
private:
    std::string name;
    int age;
    bool gender;
public:
    HashObject(){}
    HashObject(const std::string& name, int age, bool gender);
    bool operator()(const HashObject& a, const HashObject& b) const;
    bool operator==(const HashObject& b) const;
    std::size_t hashId() const;
    friend std::ostream& operator<<(std::ostream& os, const HashObject& para);
    friend struct std::hash<HashObject>;
    friend void testHash();
};

//namespace std
//{
//    template<> struct hash<HashObject>
//    {
//        std::size_t operator()(HashObject const& s) const
//        {
//            auto h1 = std::hash<std::string>()(s.name);
//            auto h2 = std::hash<int>()(s.age);
//            return h1 ^ (h2 << 1); // or use boost::hash_combine
//        }
//    };
//}
namespace std
{
    template<> struct hash<HashObject>
    {
        std::size_t operator()(HashObject const& s) const;
    };
}

void testHash();
#endif // HASH_H
