//P4170 [CQOI2007] 涂色
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str1;
    cin>>str1;
    str1 = " "+str1;
    vector<vector<long long>> dp(str1.size(),vector<long long>(str1.size(),INT_MAX));
    for(int i=1;i<dp.size();i++)
    {
        dp[i][i] = 1;
    }
    for(int i=dp.size()-2;i>=1;i--)
    {
        for(int j=i+1;j<dp.size();j++)
        {
            if(str1[i] == str1[j])
            {
                dp[i][j] = min(dp[i][j-1],dp[i+1][j]);
            }
            else{
            for(int k=i;k<j;k++)
            {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
            }
        }
    }   
    cout<<dp[1][str1.size()-1]<<endl;
    // cout<<dp[4][7]<<endl;
    // cout<<dp[5][6]<<endl;
    return 0;
}