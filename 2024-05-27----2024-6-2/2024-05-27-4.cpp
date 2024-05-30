#include<bits/stdc++.h>
using namespace std;
long long MOD = 1e9+7;
int main(){
    int n;
    cin>>n;
    vector<vector<long long>> dp(n+1,vector<long long>(10));
    dp[0][0] = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(j == 9) dp[i+1][j] = (dp[i+1][j] + 26 * dp[i][j])%MOD;
            else if(j % 3 == 1)
            {
                dp[i+1][j] = (dp[i+1][j]+dp[i][j])%MOD;
                dp[i+1][j+1] = (dp[i+1][j+1]+dp[i][j])%MOD;
                dp[i+1][j-1] = (dp[i+1][j-1] + 24*dp[i][j])%MOD;
            }
            else{
                dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j])%MOD;
                dp[i+1][j/3*3] = (dp[i+1][j/3*3] + 25 * dp[i][j])%MOD;
            }
        }
    }
    cout<<dp[n][9];
    return 0;
}