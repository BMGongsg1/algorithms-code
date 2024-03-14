//P1775 石子合并（弱化版）
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>nums[i];
    }

    vector<int> sum(n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i] = sum[i-1] + nums[i];
    }
    vector<vector<long long>> dp(n+1,vector<long long>(n+1,INT_MAX));
    for(int i=1;i<n+1;i++)
    {
        
        dp[i][i] = 0;
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=i;k<j;k++)
            {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}