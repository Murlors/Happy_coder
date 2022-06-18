/*
URL:https://codeforces.com/problemset/problem/219/A
完成日期:2022.4.24
题目大意:判断字符串能否写成n个重复的字符串
所用方法:?
*/
#include "bits/stdc++.h"
using namespace std;
char str[1010];
int k, cnt[30], times[30];
int main() {
    cin >> k >> str;
    for (int i = 0; str[i] != '\0'; i++)
        cnt[str[i] - 'a']++;
    bool flag = true;
    for (int i = 0; i <= 27; i++) {
        if (cnt[i] % k != 0) {
            flag = false;
            break;
        }
        times[i] = cnt[i] / k;
    }
    if (flag) {
        for (int i = 0; i < k; i++)
            for (int j = 0; j < 26; j++)
                if (cnt[j] != 0)
                    for (int m = 0; m < times[j]; m++)
                        cout << char('a' + j);
        cout << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}