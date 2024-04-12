#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long temp = n%(1000*60*60*24);
    long long hour = temp/(1000*60*60);
    long long min = temp/(1000*60);
    min%=60;
    long long sec = temp/(1000);
    sec%=60;
    if(hour<10) cout<<"0"<<hour;
    else cout<<hour;
    cout<<":";
    if(min<10) cout<<"0"<<min;
    else cout<<min;
    cout<<":";
    if(sec<10) cout<<"0"<<sec;
    else cout<<sec;
    
    return 0;
}