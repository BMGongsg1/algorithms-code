#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,n;
    cin>>a>>b>>n;
    int week = 5*a+2*b;
    int left = n%week;
    int have = (n/week)*7;
    int i=1;
    int cnt = 0;
    while(i<7)
    {
        if(i<=5) cnt+=a;
        else cnt+=b;
        if(cnt>=left) break;
        i++;
    }
    if(left!=0)cout<<have+i;
    else cout<<have;
    return 0;
}