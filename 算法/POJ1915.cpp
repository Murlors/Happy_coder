/*
URL:http://poj.org/problem?id=1915
完成日期:2022.4.28
所用方法:广搜
*/
#include "iostream"
#include "queue"
#include "cstring"
using namespace std;
int n, l, ex, ey, ans;
struct lo {
    int x, y, cnt;
} pre_l, next_l;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
bool mp[301][301];
queue<lo> q;
inline void bfs() {
    pre_l.cnt = 0;
    memset(mp, false, sizeof mp);
    mp[pre_l.x][pre_l.y] = true;
    q.push(pre_l);
    while (!q.empty()) {
        pre_l = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            next_l = pre_l;
            next_l.x += dx[i];
            next_l.y += dy[i];
            next_l.cnt++;
            if (next_l.x == ex && next_l.y == ey) {
                ans = next_l.cnt;
                return;
            }
            if ((next_l.x >= 0 && next_l.x < l) && (next_l.y >= 0 && next_l.y < l) && !mp[next_l.x][next_l.y]) {
                q.push(next_l);
                mp[next_l.x][next_l.y] = true;
            }
        }
    }
}
int main() {
    cin >> n;
    while (n--) {
        ans = 0;
        cin >> l;
        cin >> pre_l.x >> pre_l.y;
        cin >> ex >> ey;
        if (pre_l.x != ex || pre_l.y != ey)bfs();
        while (!q.empty()) q.pop();
        cout << ans << "\n";
    }
    return 0;
}