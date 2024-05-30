#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[1000005];
int main()
{
   
    for(int i=2;i<=100;i++)
    {
   
      int n=i;

      for(int j=2;j*j<=n;j++)
      {
   
          while(n%j==0)
          {
   
              p[j]++;
              n/=j; 
          }
      }
      if(n!=1)p[n]++;

    }
    ll ans=1;
    for(int i=2;i<=100;i++)
    {
   
        ans*=(p[i]+1);
    }
    cout<<ans;
}