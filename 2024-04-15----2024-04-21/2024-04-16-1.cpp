#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;

    vector<long long> nums(n);
    priority_queue<long long> pq;
    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        ans += nums[i];
        if(nums[i]%2==0)
        {
            pq.push(nums[i]);
        }
    }

    while(!pq.empty()&&k>0)
    {
        long long temp = pq.top();
        pq.pop();
        ans-=temp/2;
        if((temp/2)%2==0)
        {
            pq.push(temp/2);
        }
        k--;
    }
    cout<<ans;

    return 0;
}