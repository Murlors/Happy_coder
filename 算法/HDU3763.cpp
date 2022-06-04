/*
URL:http://acm.hdu.edu.cn/showproblem.php?pid=3763
完成日期:2022.6.4
题目大意:求集合A和B中有几个相同的元素
所用方法:二分查找
*/
#include "bits/stdc++.h"
using namespace std;
int n, m, cnt, tmp;
int arr[1000001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (cin >> n >> m, n | m) {
        cnt = 0;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        for (int i = 0; i < m; ++i) {
            cin >> tmp;
            if (*lower_bound(arr, arr + n, tmp) == tmp)cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}