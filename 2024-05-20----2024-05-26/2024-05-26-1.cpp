#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<long long>> dp(2024,vector<long long>(11));
    // vector<vector<vector<long long>>> dp(2023,vector<vector<long long>(2023,vector<int>(11)));

    dp[0][0] = 1;
    for(int i=1;i<2022;i++)
    {
        for(int j=2022;j>=i;j--)
        {
            for(int k=10;k>=1;k--)
            {
                dp[j][k] += dp[j-i][k-1];
            }
        }
    }
    cout<<dp[2022][10];
    return 0;
}