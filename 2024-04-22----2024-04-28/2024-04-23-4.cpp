#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<long long>> dp(n+1,vector<long long>(6));
    // 0-2
    // 1-23
    // 2-20
    // 3-201
    // 4-230
    // 5-2031
    dp[1][0] = 1;
    int MOD = 1e9+7;
    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][0]+dp[i-1][1];
        dp[i][2] = dp[i-1][0]+dp[i-1][2]*2;
        dp[i][3] = dp[i-1][2]+dp[i-1][3]*2;
        dp[i][4] = dp[i-1][1]+dp[i-1][4]*2+dp[i-1][2];
        dp[i][5] = dp[i-1][4]+dp[i-1][3]+dp[i-1][5]*2;

        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
        dp[i][2] %= MOD;
        dp[i][3] %= MOD;
        dp[i][4] %= MOD;
        dp[i][5] %= MOD;
    }

    cout<<dp[n][5];
    return 0;
}