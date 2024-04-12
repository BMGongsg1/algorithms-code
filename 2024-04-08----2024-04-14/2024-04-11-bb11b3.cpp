#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long ans = 1;
    for(int i=1;i<=2020;i++)
    {
        for(int j=1;j<=2020;j++)
        {
            if(j==i) continue;
            if(__gcd(j,i) == 1)
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}