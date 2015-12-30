#include "functionpointer.h"
#include <iostream>
using namespace std;

int sum(int a, int b){
    cout << "sum is called." << endl;
    cout << a << " + " << b << " = ";
    return a + b;
}

int min(int a, int b){
    cout << "min is called." << endl;
    cout << "min(" << a << " , " << b << ") = ";
    return (a < b) ? a : b;
}

int max(int a, int b){
    cout << "max is called." << endl;
    cout << "max(" << a << " , " << b << ") = ";
    return (a > b) ? a: b;
}

int (*getCalcFun(int i))(int a, int b){
    if(i == 0)
        return sum;
    else if(i == 1)
        return max;
    else
        return min;
}


CALC_FUN getCalcFun2(int i){
    if(i == 0){
        return sum;
    }else if(i == 1){
        return max;
    }else{
        return min;
    }
}

void testFunctionPoint(){
    int (*fun[3])(int, int) = {sum, max, min};

    for(int i = 0; i < 3; i++)
        cout << fun[i](1, 5) << endl << endl;

    for(int i = 0; i < 3; i++){
        cout << getCalcFun(i)(10, 50) << endl << endl;
    }

    for(int i = 0; i < 3; i++){
        cout << getCalcFun2(i)(100, 500) << endl << endl;
    }

    GET_CALC_FUN p = getCalcFun2;
    for(int i = 0; i < 3; i++){
        cout << p(i)(1000, 5000) << endl << endl;
    }
}
