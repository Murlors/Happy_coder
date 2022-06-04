/*
URL:http://acm.hdu.edu.cn/showproblem.php?pid=2041
完成日期:2022.6.4
题目大意:走楼梯，一次只能走一楼或者两楼
所用方法:递推
*/
#include "bits/stdc++.h"
using namespace std;
int n, m, dp[50] = {0, 0, 1, 2};
int main() {
    for (int i = 4; i <= 40; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
    cin >> n;
    while (n--) {
        cin >> m;
        if (m <= 3) cout << m - 1 << "\n";
        else cout << dp[m] << "\n";
    }
    return 0;
」