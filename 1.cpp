#include "bits/stdc++.h"
using namespace std;
int n,,ma,d[2][2]={0,1,1,0};
char tmp;
bool mp[5][5];
void dfs(int i,int j) {

}
int main() {
    while (cin >> n, n) {
        res=0,ma=0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> tmp;
                mp[i][j] = (tmp == 'X');
            }
        }
        dfs(0,0);
        cout<<ma<<"\n";
    }
    return 0;
}