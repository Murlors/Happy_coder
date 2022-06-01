/*
URL:http://poj.org/problem?id=2419
完成日期:2022.6.1
题目大意:有p个人去听t棵树倒下的声音，问有几种不同的观点数
所用方法:set<(可以尝试二进制)
*/
#include "iostream"
#include "set"
using namespace std;
int t, p, tmpt, tmpp;
set<int> st[101];
int main() {
    cin >> p >> t;
    while (cin >> tmpp >> tmpt)
        st[tmpp].insert(tmpt);
    set<set<int> > ss(st + 1, st + p + 1);
    cout << ss.size() << "\n";
    return 0;
}