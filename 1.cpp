#include "bits/stdc++.h"
using namespace std;
int n;
long long arr[40];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while(cin>>n,n){
        for (int i = 1; i <= n; ++i)
            cin>>arr[i];
        sort(arr+1,arr+n+1);
        int k=upper_bound(arr+1,arr+n+1,0)-arr;
        int i=k,j=k,sum=0;
        while(i>0||j<=n){
            if(sum>=0)
        }
    }
    return 0;
}