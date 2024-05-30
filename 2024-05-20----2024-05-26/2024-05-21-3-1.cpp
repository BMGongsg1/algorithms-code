#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(;t>0;t--)
    {
        int n,m;
        cin>>n>>m;
        vector<long long> a(n+1);
        vector<long long> b(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];

        vector<vector<long long>> dp(n+2,vector<long long>(2,LONG_LONG_MAX/10));
        dp[n+1][0] = 0;
        dp[n+1][1] = 0;
        for(int i=n;i>=1;i--)
        {
            dp[i][0] = min(dp[i+1][1],dp[i+1][0]) + a[i];
            dp[i][1] = min(dp[i+1][1],dp[i+1][0]) + b[i];
        }

        long long minn = LONG_LONG_MAX;
        for(int i=1;i<=m;i++)
        {
            // cout<<dp[i][0]<<" ";
            minn = min(minn,dp[i][0]);
        }

        cout<<minn<<endl;
    }
    return 0;
}