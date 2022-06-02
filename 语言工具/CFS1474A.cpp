/*
URL:https://codeforces.com/problemset/problem/1474/A
完成日期:2022.6.2(2022.3.16)
题目大意:给a,生成b,使得c最大(仅包含0,1,2;在c中重复的会合为一个)
所用方法:贪心
*/
#include<bits/stdc++.h>
using namespace std;
int t,n;
char s[100001],out[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        out[0] = '1';
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                if (s[i - 1] == '0') {
                    if (out[i - 1] == '0') {
                        out[i] = '1';
                    } else if (out[i - 1] == '1') {
                        out[i] = '1';
                    }
                } else if (s[i - 1] == '1') {
                    if (out[i - 1] == '0') {
                        out[i] = '1';
                    } else if (out[i - 1] == '1') {
                        out[i] = '0';
                    }
                }
            } else if (s[i] == '0') {
                if (s[i - 1] == '0') {
                    if (out[i - 1] == '0') {
                        out[i] = '1';
                    } else if (out[i - 1] == '1') {
                        out[i] = '0';
                    }
                } else if (s[i - 1] == '1') {
                    if (out[i - 1] == '0') {
                        out[i] = '0';
                    } else if (out[i - 1] == '1') {
                        out[i] = '1';
                    }
                }
            }
        }
        out[n] = '\0';
        cout << out << "\n";
    }
    return 0;
}