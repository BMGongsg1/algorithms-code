//Zuma
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
    
    vector<vector<long long>> dp(n+2,vector<long long>(n+2,INT_MAX));
    for(int i=1;i<=n;i++)
    {
        dp[i][i] = 1;
        if(i<n&&nums[i] == nums[i+1]) dp[i][i+1] = 1;
        else dp[i][i+1] = 2;
    }

    for(int i=n;i>=1;i--)
    {
        for(int j=i+2;j<=n;j++)
        {
            if(nums[i] == nums[j])
            {
                dp[i][j] = min(dp[i][j],dp[i+1][j-1]);
            }
            for(int k=i;k<j;k++)
            {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}