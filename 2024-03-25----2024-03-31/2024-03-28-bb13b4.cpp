#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int maxx = max(2*(n-i),2*(i-1));
        cout<<maxx<<endl;
    }
    return 0;
}