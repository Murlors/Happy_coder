/*
URL:http://acm.hdu.edu.cn/showproblem.php?pid=1045
完成日期:2022.4.27
题目大意:地图中有一些墙，每两个炮台之间必须有一堵墙,否则这两个炮台就会互相摧毁
所用方法:暴力DFS
*/
#include "bits/stdc++.h"
using namespace std;
int n, ma;
char mp[5][5];
bool judge(int i, int j) {
    for (int k = i; k > 0; --k) {
        if (mp[k][j] == 'X')break;
        if (mp[k][j] == 'O')return false;
    }
    for (int k = j; k > 0; --k) {
        if (mp[i][k] == 'X')break;
        if (mp[i][k] == 'O')return false;
    }
    return true;
}
void dfs(int i, int j, int cnt) {
    if (i == n && j == n) {
        if (mp[i][j] == '.' && judge(i, j)) cnt++;
        if (cnt > ma) ma = cnt;
    } else {
        if (mp[i][j] == '.' && judge(i, j)) {
            mp[i][j] = 'O';
            if (j == n)dfs(i + 1, 1, cnt + 1);
            else dfs(i, j + 1, cnt + 1);
            mp[i][j] = '.';
        }
        if (j == n)dfs(i + 1, 1, cnt);
        else dfs(i, j + 1, cnt);
    }
}
int main() {
    while (cin >> n, n) {
        ma = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cin >> mp[i][j];
        dfs(1, 1, 0);
        cout << ma << "\n";
    }
    return 0;
}