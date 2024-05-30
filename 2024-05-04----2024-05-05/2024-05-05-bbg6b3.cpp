#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,L;
    cin>>n>>L;
    vector<long long> nums(1e6+100);
    vector<long long> pre(1e6+100);
    for(int i=0;i<n;i++)
    {
        long long a,b;
        cin>>a>>b;
        nums[a] += b;
    }

    for(int i=0;i<=1e6;i++)
    {
        pre[i+1] += pre[i] +nums[i];
        
    }

    vector<vector<long long>> dp(1e6+100,vector<long long>(5,INT_MAX));
    dp[0][0] = 0;
    for(int i=1;i<=L+1;i++){
        dp[i][0] = dp[i-1][0] + pre[i];
        for(int j=1;j<4;j++)
        {
            dp[i][j] = min(dp[i][j-1],dp[i-1][j]+) 
        }
    }

    return 0;
}