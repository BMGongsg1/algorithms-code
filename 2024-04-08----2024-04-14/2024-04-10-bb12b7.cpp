#include<bits/stdc++.h>
using namespace std;
long long ans = 0;
int n;
int main(){
    cin >> n;
    vector<int> nums(n+1);
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    vector<vector<int>> dp(2,vector<int>(sum+1));
    dp[0][nums[0]] = 1;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j == nums[i]) dp[i%2][j] = 1;
            dp[i%2][j] |= dp[(i-1)%2][j];
            dp[i%2][j] |= dp[(i-1)%2][abs(j-nums[i])];
            if(j+nums[i]<=sum) dp[i%2][j] |= dp[(i-1)%2][j+nums[i]];
        }
        for(int j=0;j<=sum;j++)
        {
            dp[(i-1)%2][j] = 0;
        }
    }

    for(int i=1;i<=sum;i++)
    {
        if(dp[(n-1)%2][i])ans++;
    }
    cout<<ans;
    return 0;
}
