#include "template.h"
#include <iostream>
using namespace std;

template <class T>
Template<T>::Template (T first, T second){
    a=first;
    b=second;
}

template <class T>
T Template<T>::getmax (){
    T retval;
    retval = a>b? a : b;
    return retval;
}

//template <class T>
//void Template<T>::test(){
//    cout << "max of " << a << " and " << b << " is:" << getmax() << endl;
//}
