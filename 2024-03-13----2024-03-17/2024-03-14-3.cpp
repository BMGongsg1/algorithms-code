//P1880 [NOI1995] 石子合并
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> nums(2*n+2);
    for(int i=1;i<=n;i++)
    {
        cin>>nums[i];
        nums[i+n] = nums[i];
    }
    
    vector<int> sum(2*n+2);
    for(int i=1;i<=2*n;i++)
    {
        sum[i] = sum[i-1] + nums[i];
    }
    vector<vector<long long>> dp(2*n+2,vector<long long>(2*n+2,INT_MAX));
    for(int i=1;i<=2*n;i++)
    {
        
        dp[i][i] = 0;
    }
    for(int i=2*n;i>=1;i--)
    {
        for(int j=i+1;j<=2*n;j++)
        {
            for(int k=i;k<j;k++)
            {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    long long minn = INT_MAX;
    for(int i=1;i<=n;i++)
    {
        minn = min(minn,dp[i][i+n-1]);
    }
    cout<<minn<<endl;
    vector<vector<long long>> dp1(2*n+2,vector<long long>(2*n+2,INT_MIN));
    for(int i=1;i<=2*n;i++)
    {
        
        dp1[i][i] = 0;
    }
    for(int i=2*n;i>=1;i--)
    {
        for(int j=i+1;j<=2*n;j++)
        {
            for(int k=i;k<j;k++)
            {
                dp1[i][j] = max(dp1[i][j],dp1[i][k]+dp1[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    long long maxx = 0;
    for(int i=1;i<=n;i++)
    {
        maxx = max(maxx,dp1[i][i+n-1]);
    }
    cout<<maxx<<endl;
    return 0;
}