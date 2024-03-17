//P3205 [HNOI2010] 合唱队
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
    vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(n+1,vector<long long>(2)));
    for(int i=1;i<=n;i++)
    {
        dp[i][i][0] = 1;
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(nums[i]<nums[i+1])
            {
                dp[i][j][0] += dp[i+1][j][0];
                dp[i][j][0] %= 19650827;
            }
            if(nums[i]<nums[j])
            {
                dp[i][j][0] += dp[i+1][j][1];
                dp[i][j][0] %= 19650827;
            }
            if(nums[j]>nums[i])
            {
                dp[i][j][1] += dp[i][j-1][0];
                dp[i][j][1] %= 19650827;
            }
            if(nums[j]>nums[j-1])
            {
                dp[i][j][1] += dp[i][j-1][1];
                dp[i][j][1] %= 19650827;
            }
        }
    }
    cout<<(dp[1][n][0]+dp[1][n][1])%19650827<<endl;

    return 0;
}