#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int sum = 0;
    for(int i=1;i<n;i++)
    {
        int temp = i;
        int cnt = 0;
        for(int j=0;j<=31;j++)
        {
            if(temp&(1<<j)) cnt++;
        }
        if(cnt == k) sum++;
    }
    cout<<sum;
    return 0;
}