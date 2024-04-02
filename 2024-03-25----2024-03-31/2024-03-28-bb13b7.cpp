//积木画
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    long long n;
    cin>>n;

    long long MOD = 1e9+7;
    vector<vector<long long>> dp(3,vector<long long>(3));
    dp[1][0] = 1;
    dp[0][0] = 1;
    for(int i=2;i<=n;i++)
    {
        dp[i%3][0] = dp[(i-1)%3][0]+dp[(i-2)%3][0]+dp[(i-1)%3][1]+dp[(i-1)%3][2];
        dp[i%3][1] = dp[(i-2)%3][0]+dp[(i-1)%3][2];
        dp[i%3][2] = dp[(i-2)%3][0]+dp[(i-1)%3][1];
        dp[i%3][0]%=MOD;
        dp[i%3][1]%=MOD;
        dp[i%3][2]%=MOD;
    }
    cout<<dp[n%3][0];

    return 0;
}