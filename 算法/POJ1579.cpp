/*
URL:http://poj.org/problem?id=1579
完成日期:2022.4.29
题目大意:就是让我们优化一种递归
所用方法:DP?(记忆化搜索!)
*/
#include "iostream"
using namespace std;
int a,b,c;
int w[22][22][22];
int main() {
    for (int i = 0; i <= 20; ++i) {
        for (int j = 0; j <= 20; ++j) {
            for (int k = 0; k <= 20; ++k) {
                if (i <= 0 || j <= 0 || k <= 0)
                    w[i][j][k] = 1;
                else if (i < j && j < k)
                    w[i][j][k] = w[i][j][k - 1] + w[i][j - 1][k - 1] - w[i][j - 1][k];
                else
                    w[i][j][k] = w[i - 1][j][k] + w[i - 1][j - 1][k] + w[i - 1][j][k - 1] - w[i - 1][j - 1][k - 1];
            }
        }
    }
    while (cin >> a >> b >> c, a != -1 || b != -1 || c != -1) {
        cout << "w(" << a << ", " << b << ", " << c << ") = ";
        if (a <= 0 || b <= 0 || c <= 0)cout << "1\n";
        else if (a > 20 || b > 20 || c > 20)cout << w[20][20][20] << "\n";
        else cout << w[a][b][c] << "\n";
    }
    return 0;
}