#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    vector<pair<long long,long long>> nums(n+1);
    for(int i=1;i<=n;i++)
    {
        long long temp;
        cin>>temp;
        int last=temp%10,fst;
        while(temp)
        {
            fst = temp%10;
            temp/=10;
        }
        nums[i] = {fst,last};
        // cout<<nums[i].first<<"  "<<nums[i].second<<endl;
    }

    // vector<int> pre(n+1);
    // vector<int> aft(n+1,n+1);
    // int temp = 0;
    // unordered_map<int,int> sett;
    // for(int i=n;i>=1;i--)
    // {
    //     if(sett.find(nums[i].first)!=sett.end())
    //     {
    //         aft[i] = sett[nums[i].second];
    //     }
    //     sett[nums[i].second] = i;
    // }

    vector<vector<long long>> dp(n+1,vector<long long>(10,0));
    for(long long i=1;i<=n;i++)
    {
        for(long long j=0;j<10;j++)
        {
            dp[i][j] = dp[i-1][j] +1;
        }
        dp[i][nums[i].second] = min(dp[i][nums[i].second],dp[i-1][nums[i].first]);
    }
    long long minn = INT_MAX;
    for(int i=0;i<10;i++)
    {
        // cout<<dp[n][i]<<endl;
        minn = min(minn,dp[n][i]);
    }
    cout<<minn;

    return 0;
}