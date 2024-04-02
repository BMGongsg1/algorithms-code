//2104: [蓝桥杯2023初赛] 平均
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;

    vector<priority_queue<int,vector<int>,greater<int>>> nums(10);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        nums[a].push(b);
    }

    long long ans = 0;

    for(int i=0;i<10;i++)
    {
        while(nums[i].size()>n/10)
        {
            ans+=nums[i].top();
            nums[i].pop();
        }
    }
    cout<<ans;

    // vector<pair<int,int>> a(n);
    // for(int i=0;i<n;i++)
    // {
    //     int a1,b;
    //     cin>>a1>>b;
    //     a[i] = {a1,b};
    // }

    // function<bool(pair<int,int>,pair<int,int>) cmp = [&](pair<int,int>& a1,pair<int,int>& b)
    // {
    //     if(a1.first!=b.first)   return a1.first<b.first;
    //     else return a1.second
    // };

    // sort()

    return 0;
}