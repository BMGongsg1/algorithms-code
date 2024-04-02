//李白打酒加强版
#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    int n,m;
    cin>>n>>m;
    long long MOD = 1e9+7;
    vector<vector<vector<long long>>> dp(n+2,vector<vector<long long>>(m+1,vector<long long>(max(m+5,100))));
    // dp[0][0][2] = 1;
    // dp[1][0][4] = 1;
    // dp[0][1][1] = 1;
    // for(int i=0;i<n;i++)
    // {
    //     int temp = pow(2,i+1);
    //     if(temp<m+5)dp[i][0][temp] = 1;
    //     else break;
    // }
    dp[0][0][2] = 1;
    // dp[1][0][4] = 1;
    // dp[0][1][1] =1;
    // dp[0][2][0] =1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=m+2;k++)
            {   
                // cout<<i<<"  "<<j<<endl;
                // if(i==0&&j==0) continue;
                // else if(i==0)
                // {
                //     dp[i][j][k] +=dp[i][j-1][k/2];
                //     continue;
                // }
                // else if(j==0)
                // {
                //     dp[i][j][k] +=dp[i-1][j][k+1];
                //     continue;
                // }
                if(k%2==0)
                {
                    if(i>0)dp[i][j][k] += dp[i-1][j][k/2];
                }
                if(j>0)dp[i][j][k] += dp[i][j-1][k+1];
                dp[i][j][k] %= MOD;
                // cout<<i<<"  "<<j<<"  "<<k<<" "<<dp[i][j][k]<<endl;

            } 
        }
    }
    cout<<dp[n][m-1][1];

    return 0;
}