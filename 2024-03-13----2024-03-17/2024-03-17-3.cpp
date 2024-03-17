//P1063 [NOIP2006 提高组] 能量项链
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> nums(3*n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>nums[i];
        nums[i+n] = nums[i];
        nums[2*i+n] = nums[i];
    }

    vector<vector<long long>> dp(nums.size(),vector<long long>(nums.size()));
    for(int i=2*n;i>=1;i--)
    {
        for(int j=i+1;j<=i+n-1;j++)
        {
            for(int k=i;k<j;k++)
            {
                dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]+nums[i]*nums[k+1]*nums[j+1]);
            }
        }
    }
    long long ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans = max(ans,dp[i][i+n-1]);
    }
    // cout<<dp[4][7]<<endl;
    cout<<ans<<endl;
    return 0;
}