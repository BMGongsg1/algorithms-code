//2084: [蓝桥杯2023初赛] 整数删除(修正版)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<long long> a(n+2);
    vector<long long> pre(n+2);
    vector<long long> af(n+2); 
    vector<long long> flag(n+2);
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i] = i-1;
        af[i] = i+1;
        q.push({a[i],i});
    }
    while(q.size()>n-k)
    {
        auto temp = q.top();
        q.pop();
        if(flag[temp.second] == 1)
        {
            q.push({a[temp.second],temp.second});
            flag[temp.second] = 0;
        }
        else
        {
            int before = pre[temp.second]; 
            int after = af[temp.second];
            pre[after] = before;
            af[before] = after;
            a[before] += temp.first;
            a[after] += temp.first;
            a[temp.second] = 0;
            flag[before] = 1;
            flag[after] = 1;
            flag[temp.second] = -1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(flag[i] != -1)
        {
            cout<<a[i]<<" ";
        }
    }

    return 0;
}