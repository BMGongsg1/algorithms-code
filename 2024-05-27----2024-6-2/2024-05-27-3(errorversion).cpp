#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long MOD = 1e9+7;
    vector<vector<long long>> dp(n+1,vector<long long>(5));
    dp[0][0] = 1;
    for(int i=1;i<=n;i++)
    {
        if(i>=3)
        {
            for(int j=3;j>0;j--)
            {
                if(j == 3)
                {
                    dp[i][j] += dp[i-3][j-1];
                    dp[i][j]%=MOD;
                    dp[i][j] += dp[i-3][j];
                    dp[i][j]%=MOD;
                }
                else
                {
                    dp[i][j] += dp[i-3][j-1];
                    dp[i][j] %= MOD;
                }
            }
        }
        for(int j=0;j<=3;j++) {
            dp[i][j] += dp[i-1][j]*26;
            dp[i][j]%=MOD;
        }
    }

    cout<<dp[n][3];
    return 0;
}