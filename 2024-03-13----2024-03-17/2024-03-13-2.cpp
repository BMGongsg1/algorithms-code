#include<bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    cin>>n;
    vector<vector<int>> nums(n+1,vector<int>(2));
    for(int i=1;i<=n;i++)
    {
        cin>>nums[i][0]>>nums[i][1];
    }

    int p = 400000;
    vector<int> dp(800005,INT_MIN);
    dp[400000] = 0;
    for(int i=1;i<=n;i++)
    {
        if(nums[i][0]>=0)
        {
            for(int j=800004-nums[i][0];j>=0;j--)
            {
                if(dp[j]!=INT_MIN)
                {
                    dp[j+nums[i][0]] = max(dp[j+nums[i][0]],dp[j]+nums[i][1]);
                    // cout<<j<<"  "<<dp[j]<<endl;
                }
            }
        }
        else
        {
            for(int j=-nums[i][0];j<=800004;j++)
            {
                if(dp[j]!=INT_MIN)
                {
                    dp[j+nums[i][0]] = max(dp[j+nums[i][0]],dp[j]+nums[i][1]);
                    // cout<<j<<"  "<<dp[j]<<endl;
                }
            }
        }
    }
    int maxx = 0;
    for(int i=p;i<dp.size();i++)
    {
        if(dp[i]>=0)maxx = max(maxx,dp[i]+i-p);
        // if(dp[i]!=INT_MIN)
        // {
        //     cout<<i<<"  "<<dp[i]<<endl;
        // }
    }
    cout<<maxx<<endl;
    return 0;
}