#include<bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    string a1,a2;
    int n;
    cin>>a1>>a2>>n;
    int h1=0,flag = 0,h2=0,m1=0,m2=0;
    for(int i=0;i<a1.size();i++)
    {
        if(a1[i] == ':')
        {
            flag = 1;
            continue;
        }
        if(!flag)
        {
            h1*=10;
            h1 += a1[i]-'0';
        }
        else
        {
            m1*=10;
            m1+=a1[i]-'0';
        }
    }
    flag = 0;
    for(int i=0;i<a2.size();i++)
    {
        if(a2[i] == ':')
        {
            flag = 1;
            continue;
        }
        if(!flag)
        {
            h2*=10;
            h2 += a2[i]-'0';
        }
        else
        {
            m2*=10;
            m2+=a2[i]-'0';
        }
    }
    m1+=h1*60;
    m2+=h2*60;
    int m = m2-m1;
    vector<vector<int>> nums(n+1,vector<int>(3));
    for(int i=1;i<=n;i++)
    {
        cin>>nums[i][0]>>nums[i][1]>>nums[i][2];
    }
    // function<bool(vector<int>,vector<int>)> cmp = [&](vector<int>& b,vector<int>& a)->bool{
    //     return 
    // };

    vector<int> dp(m+1);
    function<void(int,int)> zeroone = [&](int weight,int cost){
        for(int i=dp.size()-1;i>=weight;i--)
        {
            dp[i] = max(dp[i],dp[i-weight] + cost);
        }
    };
    function<void(int,int)> comp = [&](int weight,int cost)
    {
        for(int i=weight;i<dp.size();i++)
        {
            dp[i] = max(dp[i-weight] + cost,dp[i]);
        }
    };
    function<void(int,int,int)> mult = [&](int weight,int cost,int k)
    {
        for(int i=0;(1<<i)<k;i++)
        {
            zeroone(weight*(1<<i),cost*(1<<i));
            k -= (1<<i);
        }
        zeroone(weight*k,cost*k);
    };

    for(int i=1;i<=n;i++)
    {
        if(nums[i][2] == 0)
        {
            comp(nums[i][0],nums[i][1]);
        }
        else
        {
            mult(nums[i][0],nums[i][1],nums[i][2]);
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}