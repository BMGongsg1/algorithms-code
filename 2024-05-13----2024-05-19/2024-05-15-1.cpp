#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,n;
    cin>>a>>b>>n;
    a*=n*1000;
    cout<<(a/b)%1000;
    return 0;
}