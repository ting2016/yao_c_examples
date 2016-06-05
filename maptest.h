#ifndef MAPTEST_H
#define MAPTEST_H
#include <iostream>
class MapKeyClass1
{
public:
    MapKeyClass1(int);
private:
    int value;

    friend struct KeyClassCompare;
    friend std::ostream& operator<<(std::ostream& os, const MapKeyClass1& obj);
};


struct KeyClassCompare
{
   bool operator() (const MapKeyClass1& lhs, const MapKeyClass1& rhs) const
   {
       return lhs.value < rhs.value;
   }
};

class MapKeyClass2
{
public:
    MapKeyClass2(int v): value(v){}
    bool operator<(const MapKeyClass2& obj) const;

private:
    int value;

    friend std::ostream& operator<<(std::ostream& os, const MapKeyClass2& obj);
};

void testMapKey();

#endif // MAPTEST_H
