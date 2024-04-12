#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long l=0,r = n;
    while(l<=r)
    {
        long long mid = l+(r-l>>1);
        long long temp = mid*(mid-1)/2;
        if(temp>=n)
        {
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    cout<<l-1<<endl;
    return 0;
}