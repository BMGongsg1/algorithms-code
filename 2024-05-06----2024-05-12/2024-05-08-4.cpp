#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<long long> dp(n+1,INT_MAX);
    int now = 0;
    for(int i=0;i<n;i++){
        dp[now] = min(dp[now],0LL+i);
        now += k;
        now %= n;
    }

    long long maxx = 0;
    for(int i=1;i<n;i++){
        dp[i] = min(dp[i],dp[i-1]+1);
        // cout<<dp[i]<<endl;
        maxx = max(dp[i],maxx);
    }
    cout<<maxx;

    return 0;
}