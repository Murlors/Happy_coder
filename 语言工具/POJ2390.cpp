/*
URL:http://poj.org/problem?id=2390
完成日期:2022.6.3
题目大意:...
所用方法:水题
*/
#include "iostream"
using namespace std;
double r,m;
int y;
int main() {
    cin >> r >> m >> y;
    r = r / 100 + 1;
    for (int i = 0; i < y; ++i)
        m *= r;
    cout << (int) m << "\n";
    return 0;
}