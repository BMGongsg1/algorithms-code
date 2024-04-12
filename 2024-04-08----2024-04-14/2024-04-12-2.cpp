#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m;
    cin>>n>>m;
    vector<long long> dp(n+1);
    vector<vector<long long>> nums(m+1,vector<long long>(2));
    for(int i=1;i<=m;i++)
    {
        cin>>nums[i][0]>>nums[i][1];
    }


    for(int i=1;i<=m;i++)
    {
        for(int j=n;j>=0;j--)
        {
            if(j+nums[i][0]<=n)
            {
                dp[j] = max(dp[j+nums[i][0]] + nums[i][1],dp[j]);
            }
        }
    }

    long long maxx = 0;
    for(int i=0;i<=n;i++)
    {
        maxx = max(maxx,dp[i]);
    }
    cout<<maxx;

    return 0;
}