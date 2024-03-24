//2081: [蓝桥杯2023初赛] 接龙数列
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;
    vector<pair<int,int>> a(k);
    for(int i=0;i<k;i++)
    {
        int temp;
        cin>>temp;
        int fst,lst=temp%10;
        while(temp)
        {
            fst = temp%10;
            temp/=10;
        }
        a[i].first=fst;
        a[i].second=lst;
    }

    vector<long long> dp(10,0);
    vector<long long> last_dis(10,-1);
    // for(int i=0;i<a.size();i++)
    // {
    //     if(last_dis[a[i].first] == -1)
    //     {
    //         dp[a[i].second] = i;
    //     }
    //     else
    //     {
    //         dp[a[i].second] = dp[a[i].first] + (i - last_dis[a[i].first] - 1);
    //     }

    //     last_dis[a[i].second] = i;
    // }

    for(int i=0;i<a.size();i++)
    {
        // cout<<dp[a[i].second]<<"asdasd  "<<dp[a[i].first]<<"  "<<i<<endl;
        dp[a[i].second] = min(dp[a[i].second]+1,dp[a[i].first]);
        for(int j=0;j<10;j++)
        {
            if(j==a[i].second)
            {
                continue;
            }
            else
            {
                dp[j]++;
            }
        }
        // cout<<dp[1]<<"  "<<dp[2]<<"  "<<dp[3]<<endl;
    }
    long long minn = INT_MAX;
    for(int i=0;i<10;i++)
    {
        minn = min(minn,dp[i]);
    }
    cout<<minn<<endl;
    return 0;
}