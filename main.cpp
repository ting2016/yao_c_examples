#include <vector>
#include <iostream>
#include <memory>
#include <fstream>
#include <template.h>
template <class T>
class Tools{
public:
    T static ad_find (T first, T last);
};

template <class T>
T Tools<T>::ad_find (T first, T last)
{
    if (first != last)
    {
        T next=first; ++next;
        while (next != last) {
            if (*first == *next)     // or: if (pred(*first,*next)), for version (2)
                return first;
            ++first; ++next;
        }
    }
    return last;
}


template <class T>
class MyClass {
    T a, b;
public:
    MyClass (T first, T second)
    {a=first; b=second;}
    T getmax ();
};

template <class T>
T MyClass<T>::getmax ()
{
    T retval;
    retval = a>b? a : b;
    return retval;
}


#include <iostream>
using namespace std;

class Date
{
    int mo, da, yr;
public:
    Date(int m, int d, int y)
    {
        mo = m; da = d; yr = y;
    }
    friend ostream& operator<<(ostream& os, const Date& dt);
};

ostream& operator<<(ostream& os, const Date& dt)
{
    os << dt.mo << '/' << dt.da << '/' << dt.yr;
    return os;
}

#include <variadicparameters.h>
int main()
{
    std::ofstream logFile;
    logFile.open("/tmp/log.txt");
    Date dt(5, 6, 92);
    std::cout << __func__ << dt << std::endl;
    logFile << __func__ << dt << std::endl;

    VariadicParameters::test();
    MyClass<int> t(100, 200);
}

//int main(){
//    std::vector<int> x = {1, 22, 22, 30};
////    std::cout << (Tools<int>::ad_find(x.cbegin(), x.cend())) << std::endl;

//}
