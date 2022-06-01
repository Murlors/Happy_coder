/*
URL:https://nanti.jisuanke.com/t/T3101
完成日期:2022.6.1
题目大意:判断字符串是否存在特殊关系
所用方法:hash
*/
#include <bits/stdc++.h>
using namespace std;
int n, h1[26*26*26*27], h2[26*26*26*27];
char s1[20], s2[20];
long long ans;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        if (!(s1[0] == s2[0] && s1[1] == s2[1])) {//头两个字母不相等
            h1[(((s1[0] - 'A') * 26 + s1[1] - 'A') * 26 + (s2[0] - 'A')) * 26 + s2[1] - 'A']++;
            h2[(((s2[0] - 'A') * 26 + s2[1] - 'A') * 26 + (s1[0] - 'A')) * 26 + s1[1] - 'A']++;
        }
    }
    for (int i = 0; i < 26 * 26 * 26 * 27; i++)
        ans += h1[i] * h2[i];
    cout << ans / 2 << endl;
    return 0;
}