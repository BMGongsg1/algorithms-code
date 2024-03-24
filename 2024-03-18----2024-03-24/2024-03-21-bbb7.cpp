//2084: [蓝桥杯2023初赛] 整数删除(极限超时)
#include<bits/stdc++.h>
using namespace std;
struct Hash{
    size_t operator()(const pair<long long,long long>& p) const{
        auto hash1 = hash<long long>{}(p.first);
        auto hash2 = hash<long long>{}(p.second);
        return hash1 ^ hash2;
    }
};
int main()
{
    long long n,k;
    cin>>n>>k;
    vector<long long> a(n);
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
    map<long long,pair<long long,long long>> mapp;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        q.push({a[i],i});
        if(i==0)
        {
            mapp[i] = {-1,1};
        }
        else if(i==n-1)
        {
            mapp[i] = {i-1,-1};
        }
        else
        {
            mapp[i] = {i-1,i+1};
        }
    }

    unordered_set<pair<long long,long long>,Hash> sett;
    for(int i=0;i<k;i++)
    {
        while(!q.empty()&&sett.find(q.top())!=sett.end())
        {
            sett.erase(q.top());
            q.pop();
        }
        auto temp = q.top();
        long long now_index = temp.second;
        long long now_left = mapp[temp.second].first;
        long long now_right = mapp[temp.second].second;
        if(now_left==-1)
        {
            mapp[now_right].first = -1;
            sett.insert({a[now_right],now_right});
            a[now_right] += temp.first;
            mapp[now_index].second = -1;
        }
        if(now_right==-1)
        {
            mapp[now_left].second = -1;
            sett.insert({a[now_left],now_left});
            a[now_left] += temp.first;
            mapp[now_index].first = -1;
        }
        if(now_left!=-1&&now_right!=-1)
        {
            mapp[now_left].second = now_right;
            mapp[now_right].first = now_left;
            sett.insert({a[now_left],now_left});
            sett.insert({a[now_right],now_right});
            a[now_left] += temp.first;
            a[now_right] += temp.first;
            mapp[now_index].first =-1;
            mapp[now_index].second =-1;
        }
        // cout<<temp.first<<"  "<<temp.second<<endl;
        q.pop();
        q.push({a[now_left],now_left});
        q.push({a[now_right],now_right});
    }
    vector<long long> ans;
    for(auto [a1,b]:mapp)
    {
        if(b.first==-1&&b.second==-1) continue;
        // cout<<a1<<" "<<b.first<<"  "<<b.second<<endl;
        ans.push_back(a[a1]);
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}