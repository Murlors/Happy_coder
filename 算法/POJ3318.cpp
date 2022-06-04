/*
URL:http://poj.org/problem?id=3318
完成日期:2022.6.3
题目大意:矩阵相乘,判断AXB是否等于C
所用方法:随机化算法(MonteCarlo,蒙特卡罗算法)————待学习
*/
#include "cstdio"
#include "cstring"
#include "cstdlib"
using namespace std;
int n,a[501][501],b[501][501],c[501][501],r[501],br[501],cr[501],abr[501];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &b[i][j]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &c[i][j]);
    bool flag = true;
    for (int k = 0; k < 10; ++k) {
        memset(br, 0, sizeof br);
        memset(cr, 0, sizeof cr);
        memset(abr, 0, sizeof abr);
        for (int i = 0; i < n; ++i)
            r[i] = rand() % 100;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                br[i] += b[i][j] * r[j];
                cr[i] += c[i][j] * r[j];
            }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                abr[i] += a[i][j] * br[j];
        for (int i = 0; i < n; ++i)
            if (abr[i] != cr[i]) {
                flag = false;
                break;
            }
        if (!flag) break;
    }
    if (flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}