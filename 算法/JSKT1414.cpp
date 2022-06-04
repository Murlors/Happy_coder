/*
URL:https://nanti.jisuanke.com/t/T1414
完成日期:2022.6.4
题目大意:图像框外变黑
所用方法:DFS(可以尝试BFS)还是很不熟练！！！
*/
#include "bits/stdc++.h"
using namespace std;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int n,w,h,im[970][1450],out[970][1450];
bool vis[970][1450];
void dfs(int x,int y) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    out[x][y] = 0;
    vis[x][y] = true;
    int i, j;
    for (int k = 0; k < 4; ++k) {
        i = x + dx[k], j = y + dy[k];
        if (i > 0 && j > 0 && i <= h && j <= w && !vis[i][j] && im[i][j])
            dfs(i, j);
    }
}
int main() {
    cin >> n;
    while (n--) {
        int x0 = 0, y0 = 0;
        memset(vis, false, sizeof vis);
        cin >> w >> h;
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= w; ++j) {
                cin >> im[i][j];
                out[i][j] = im[i][j];
                if (im[i][j] && !(x0 | y0))
                    x0 = i, y0 = j;
            }
        dfs(x0, y0);
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j)
                cout << out[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}