/*
URL:http://acm.hdu.edu.cn/showproblem.php?pid=6433
完成日期:2022.5.7
题目大意:计算2的幂(幂次小于1000)
所用方法:double存储原理(IEEE754)
*/
#include "bits/stdc++.h"
using namespace std;
int t,n;
int main() {
    cin>>t;
    while (t--) {
        cin >> n;
        cout << fixed << setprecision(0) << pow(2, n) << "\n";
    }
    return 0;
}