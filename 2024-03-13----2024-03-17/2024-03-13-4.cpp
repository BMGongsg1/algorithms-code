//P3147 [USACO16OPEN] 262144 P
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>nums[i];
    }

    vector<vector<int>> dp(59,vector<int>(n+3));
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        dp[nums[i]][i] = i+1;
        ans = max(ans,nums[i]);
    }
    for(int i=1;i<=58;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dp[i-1][dp[i-1][j]]!=0)
            {
                dp[i][j] = dp[i-1][dp[i-1][j]];
                ans = max(ans,i);
            }
        }
    }
    
    cout<<ans<<endl;
    return 0;
}