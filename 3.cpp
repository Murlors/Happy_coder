#include "bits/stdc++.h"
using namespace std;
int n,m,a,b,s[1000001];
set<int> st;
int finds(int x) {
    while (s[x] != x) x = s[x];
    return x;
}
int merges(int a, int b) {
    int fa = finds(a), fb = finds(b);
    if (fa != fb) {
        s[fa] = fb;
        return 1;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i = 1; i <=n; ++i)
        s[i]=i;
    for (int i = 0; i < m; ++i){
        cin>>a>>b;
        if(a<b) swap(a,b);
        merges(a,b);
    }
    for (int i = 1; i <= n; ++i){
        int k = finds(s[i]);
        if(k!=i) st.insert(k);
    }
    cout<<st.size()<<"\n";
    return 0;
}