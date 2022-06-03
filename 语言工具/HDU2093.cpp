/*
URL:http://acm.hdu.edu.cn/showproblem.php?pid=2093
完成日期:2022.6.3
题目大意:求ACM比赛排名
所用方法:模拟...
*/
#include "bits/stdc++.h"
using namespace std;
int n, m;
string name, score;
struct stu {
    string name;
    int cnt, time;
    bool operator<(const stu &p) const {
        return (cnt == p.cnt) ? (time == p.time) ? name < p.name : time < p.time : cnt > p.cnt;
    }
}tmp;
vector<stu> v;
int main() {
    cin >> n >> m;
    while (cin >> name) {
        int cnt = 0, time = 0;
        for (int i = 0; i < n; ++i) {
            cin >> score;
            if (score[0] == '-' || score[0] == '0')
                continue;
            cnt++;
            if (score.find("(") != score.npos) {
                int times = 0;
                for (int j = score.find("(") + 1; score[j] != ')'; ++j)
                    times = times * 10 + score[j] - '0';
                time += times * m;
            }
            int k = 0;
            for (int j = 0; isdigit(score[j]); ++j)
                k = k * 10 + score[j] - '0';
            time += k;
        }
        tmp = {name, cnt, time};
        v.emplace_back(tmp);
    }
    sort(v.begin(), v.end());
    for (auto i: v) {
        cout.setf(ios::left);
        cout << setw(10) << i.name << " ";
        cout.unsetf(ios::left);
        cout.setf(ios::right);
        cout << setw(2) << i.cnt << " " << setw(4) << i.time << "\n";
        cout.unsetf(ios::right);
    }
    return 0;
}