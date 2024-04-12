#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;


    vector<int> f(1010);
    auto pd = [&]()
    {
        for(int i=2;i<=26;i++) f[i] = f[i-1]+i-1;
        int sum = 26,vis[30];
        for(int i=0;i<26;i++) vis[i] = 1;
        for(int i=27;f[i-1]<n;i++,sum++)
        {
            int ch = (i%26-1+26)%26;
            f[i] = f[i-1] + sum - vis[ch];
            vis[ch]++;
        }
    };

    vector<int> cnt(30);
    vector<int> vis(30);
    auto get_add = [&](int ch) -> int{
        int add = 0;
        for(int i=0;i<ch;i++) add += vis[i];
        for(int i=ch+1;i<26;i++) add += cnt[i] + vis[i];
        return add;
        
    };

    auto check = [&](int id,int m,int ch,int sum)->bool{
        for(int i = id + 1;i<=m;i++)
        {
            int maxadd = 0,ch1 = 0;
            for(int j=0;j<26;j++)
            {
                int add = get_add(j);
                if(maxadd<add){
                    maxadd = add;
                    ch1 = j;
                }
            }
            vis[ch1]++;
            sum+=maxadd;
        }
        for(int i=0;i<vis.size();i++) vis[i] = 0;
        if(sum>=n) return true;
        return false;
    };

    auto solve = [&](int m){
        int sum = 0;
        string ans;
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<26;j++)
            {
                int initadd = get_add(j);
                cnt[j]++;
                sum+=initadd;
                if(check(i,m,j,sum)){
                    ans+=('a'+j);
                    break;
                }
                cnt[j]--;
                sum-=initadd;
            }
        }
        cout<<ans;
    };

    cin>>n;
    pd();
    for(int i=2;i<=n;i++)
    {
        if(f[i]>=n)
        {
            solve(i);
            break;
        }
    }

    return 0;
}