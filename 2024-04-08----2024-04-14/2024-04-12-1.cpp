#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    vector<vector<int>> nums(m+1,vector<int>(2));
    for(int i=1;i<=m;i++)
    {
        cin>>nums[i][0]>>nums[i][1];
    }


    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j+nums[i][0]<=n)
            {
                dp[j][i] = max(dp[j+nums[i][0]][i-1]+nums[i][1]*nums[i][0],dp[j][i]);
            }
            dp[j][i] = max(dp[j][i],dp[j][i-1]);
        }
    }

    int maxx = 0;
    for(int i=0;i<=n;i++)
    {
        maxx = max(maxx,dp[i][m]);
    }
    cout<<maxx;

    return 0;
}