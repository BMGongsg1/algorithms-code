#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,k;
    long long MOD = 998244353;
    cin>>n>>m>>k;

    if(k == 0)
    {
        long long temp = 1;
        for(int i=1;i<=n;i++)
        {
            temp*=m;
            temp%=MOD;
        }
        cout<<temp<<endl;
        return 0;
    }
    vector<long long> dp(m+1);
    vector<long long> pre(m+1);
    for(int i=1;i<dp.size();i++)
    {
        // dp[i] = 1;
        pre[i] = pre[i-1] + 1;
        // cout<<pre[i]<<endl;
    }
    
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j-k>=1)
            {
                // cout<<i<<"  "<<j<<"  "<<dp[j]<<"  "<<pre[j-k]<<endl;
                dp[j] += pre[j-k];
                dp[j] %= MOD;
            }
            if(j+k<=m)
            {
                dp[j] += (pre[m]-pre[j+k-1]+MOD)%MOD;
                dp[j] %= MOD;
            }
        }
        for(int j=1;j<=m;j++)
        {
            
            pre[j] = pre[j-1]+dp[j];
            pre[j] %= MOD;
            if(i!=n) dp[j] = 0;
            // cout<<pre[j]<<"  ";
        }
        // cout<<endl;
    }

    long long ans = 0;

    cout<<pre[m];

    return 0;
}