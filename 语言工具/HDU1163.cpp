/*
URL:http://poj.org/problem?id=2785
完成日期:2022.6.2
题目大意:四数之和为0
所用方法:九余数定理(num=999*a+99*b+9*c+(a+b+c+d),num%9=(a+b+c+d)%9)、
        同余定理(两个乘积除以m的余数等于这两个数分别除以m的余数的积)
*/
#include "bits/stdc++.h"
using namespace std;
int n,tp;
int main() {
    while (cin >> n, n) {
        tp = 1;
        for (int i = 0; i < n; i++)
            tp = tp * n % 9;
        cout << (tp == 0 ? 9 : tp) << "\n";
    }
    return 0;
}