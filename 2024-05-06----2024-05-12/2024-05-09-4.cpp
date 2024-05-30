#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s;
    cin>>t;
    vector<vector<long long>> dp(s.size()+1,vector<long long>(t.size()+1,INT_MAX));
    for(int i=0;i<s.size();i++)
    {
        dp[i][0] = 0;
    }
    for(int i=0;i<s.size();i++){
        for(int j=0;j<t.size();j++){
            if(s[i] == t[j])
            {
                dp[i+1][j+1] = min(dp[i][j+1],dp[i][j]);
            }
            dp[i+1][j+1] = min(dp[i][j+1],min(dp[i][j]+1,dp[i+1][j+1]));
        }
    }
    cout<<dp[s.size()][t.size()];
    return 0;
}