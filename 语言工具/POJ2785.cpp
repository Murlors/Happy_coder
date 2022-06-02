/*
URL:http://poj.org/problem?id=2785
完成日期:2022.6.2
题目大意:四数之和为0
所用方法:二分
*/
#include "iostream"
#include "algorithm"
using namespace std;
int n,ans,cnt,a[4001],b[4001],c[4001],d[4001];
int ab,cd[16000001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cd[cnt++] = c[i] + d[j];
    sort(cd, cd + cnt);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            ab = a[i] + b[j];
            ans += upper_bound(cd, cd + cnt, -ab) - lower_bound(cd, cd + cnt, -ab);
        }
    }
    cout << ans << "\n";
    return 0;
}