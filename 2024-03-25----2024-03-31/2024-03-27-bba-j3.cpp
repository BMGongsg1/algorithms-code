//2098: [蓝桥杯2023初赛] 阶乘的和(合成大西瓜,小逻辑错误，但是需要大改)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    bool flag = 0;
    long long minn = 0;
    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    deque<pair<long long,long long>> d;
    for(int i=0;i<a.size();i++)
    {
        d.push_back({a[i],1});
    }
    while(d.size()>1)
    {
        auto [ai,id] = d.front();
        long long aii = ai,idd = id;
        d.pop_front();
        while(!d.empty()&&ai == d.front().first)
        {
            id+=d.front().second;
            d.pop_front();
        }
        while(ai<id&&id%(ai+1)==0)
        {
            // cout<<ai<<"  "<<id<<endl;
            id = id/(ai+1);
            ai = ai+1;
            flag = 1;
            // cout<<"ASDASD"<<ai<<"  "<<id<<endl;
        }
        if(!flag&&minn==0)
        {
            minn = ai;
        }
        flag = 0;
        if(ai!=aii||id!=idd)d.push_front({ai,id});
        // cout<<d.size()<<endl;
    }
    if(minn)
    {
        cout<<minn;
    }
    else
    {
        cout<<d.front().first;
    }
    return 0;
}