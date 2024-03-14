//P4310 绝世好题
#include<bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    vector<int> dp(40);
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        int step = 0;
        int maxx = 0;
        int temp = a[i];
        while(a[i]>0)
        {
            if(a[i]%2==1)
            {
                maxx = max(maxx,dp[step]+1);
            }
            a[i]/=2;
            step++;
        }
        step=0;
        while(temp>0)
        {
            if(temp%2==1)
            {
                dp[step] = maxx;
            }
            temp/=2;
            step++;
        }
        ans = max(ans,maxx);
    }
    cout<<ans<<endl;
    return 0;
}