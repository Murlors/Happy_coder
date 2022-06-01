/*
URL:https://codeforces.com/problemset/problem/870/C
完成日期:2022.6.1
题目大意:拆分成尽可能多的合数之和
所用方法:数论,偶数的话用4、6就可以满足，奇数的话减去一个9就成偶数了
*/
#include "bits/stdc++.h"
using namespace std;
long long q, n;
int main() {
    cin >> q;
    while (q--) {
        cin >> n;
        if (n < 4 || n == 5 || n == 7 || n == 11)
            cout << -1 << "\n";
        else if (n % 4 == 0 || n % 4 == 2)
            cout << n / 4 << "\n";
        else if (n % 4 == 1 || n % 4 == 3)
            cout << n / 4 - 1 << "\n";
    }
    return 0;
}