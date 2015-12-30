#pragma once
typedef int (*CALC_FUN)(int, int);
typedef CALC_FUN (*GET_CALC_FUN)(int);

using namespace std;
int sum(int a, int b);
int min(int a, int b);
int max(int a, int b);
int (*getCalcFun(int i))(int a, int b);
CALC_FUN getCalcFun2(int i);
void testFunctionPoint();
