#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,x;
    cin>>n>>x;
    // vector<int> nums(n);
    long long sum = x;
    for(int i=0;i<n;i++){
        long long temp;
        cin>>temp;
        if(temp<=sum) sum+=temp;
        else sum+=__gcd(sum,temp);
    }
    cout<<sum;
    return 0;
}