#include "bits/stdc++.h"
using namespace std;
int score[6][6]={0,0,0,0,0,0,
                0,5,-1,-2,-1,-3,
                0,-1,5,-3,-2,-4,
                0,-2,-3,5,-2,-2,
                0,-1,-2,-2,5,-1,
                0,-3,-4,-2,-1,0};
char ch;
int t,la,lb,a[110],b[110],dp[110][110];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>la;
        for (int i = 1; i <= la; ++i){
            cin>>ch;
            if(ch=='A')a[i]=1;
            else if(ch=='C')a[i]=2;
            else if(ch=='G')a[i]=3;
            else if(ch=='T')a[i]=4;
        }
        cin>>lb;
        for (int i = 1; i <= lb; ++i){
            cin>>ch;
            if(ch=='A')b[i]=1;
            else if(ch=='C')b[i]=2;
            else if(ch=='G')b[i]=3;
            else if(ch=='T')b[i]=4;
        }
        for (int i = 1; i <= la; ++i)
            dp[i][0]=dp[i-1][0]+score[5][a[i]];
        for (int i = 1; i <= lb; ++i)
            dp[0][i]=dp[0][i-1]+score[b[i]][5];
        for (int i = 1; i <=la ; ++i)
            for (int j = 1; j <=lb ; ++j)
                dp[i][j]=max(dp[i-1][j-1]+score[b[j]][a[i]],max(dp[i-1][j]+score[5][a[i]],dp[i][j-1]+score[b[j]][5]));
        cout<<dp[la][lb]<<"\n";
    }
    return 0;
}