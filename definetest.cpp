#include "definetest.h"
#include <iostream>
using namespace std;
void testDefine(){
    cout << MAX(23 + 20, MAX(32, 79)) << endl;
    int a[10];
    for(int i = 0; i < 10; i++){
        a[i] = i + 1;
    }

    int T_1 = 100, T_2 = 200, T_3 = 300;
    cout << A(1) << endl;
    cout << A(2) << endl;
    cout << A(3) << endl;
}
