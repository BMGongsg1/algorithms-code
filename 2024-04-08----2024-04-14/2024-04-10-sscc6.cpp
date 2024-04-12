#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n;
    cin>>n;
    long long MOD = 1e9 + 7;
    unordered_map<int,int> mapp;
    for(int i = 0;i<n;i++)
    {
        int temp;
        cin>>temp;
        mapp[temp]++;
    }

    int step = 1;
    long long ans = 0;
    for(auto [a,b]:mapp)
    {
        ans += ans*b;
        ans %= MOD;
        ans += b;
        ans %= MOD;
    }
    cout<<ans<<endl;

    return 0;
}