#ifndef BAR_H
#define BAR_H
#include <istream>
namespace yao{
class Bar;
}

class yao::Bar
{
public:
    Bar() : Bar(0){}
    Bar(const int &v) : v(v) {}
    Bar(const Bar& other);
    Bar& operator = (const Bar& other);

private:
    int v;

    friend inline std::ostream& operator<<(std::ostream& os, const Bar& obj){
        return os << obj.v;
    }
};

#endif // BAR_H
