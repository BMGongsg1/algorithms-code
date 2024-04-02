//2098: [蓝桥杯2023初赛] 阶乘的和(修复版)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    map<int,int> mapp;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        mapp[temp]++;
    }
    for(auto[a,b]:mapp)
    {
        if(b%(a+1)==0)
        {
            mapp[a+1]+=b/(a+1);
        }
        else
        {
            cout<<a;
            break;
        }
    }
    return 0;
}