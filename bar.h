#ifndef BAR_H
#define BAR_H
#include <istream>
namespace yao_bar{
class Bar;
}

class yao_bar::Bar
{
public:
    Bar() : Bar(0){}
    Bar(const int &v) : v(v) {}
    Bar(const Bar& other);
    Bar& operator = (const Bar& other);

public:
    int getV() const;
    std::ostream& stream_write(std::ostream& os) const;
private:
    int v;

    friend inline std::ostream& operator<<(std::ostream& os, const Bar& bar);
};

#endif // BAR_H
