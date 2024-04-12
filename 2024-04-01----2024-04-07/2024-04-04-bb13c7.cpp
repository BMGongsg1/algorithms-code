#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    long long n;
    cin>>n;
    vector<long long> nums(n+1);
    for(int i=1;i<nums.size();i++)
    {
        cin>>nums[i];
    }

    long long m;
    cin>>m;

    vector<long long> cf(n+2);

    for(int i=0;i<m;i++)
    {
        int left,right;
        cin>>left>>right;
        cf[left]+=1;
        cf[right+1] -= 1;
    }

    long long before = 0;
    for(int i=1;i<=n;i++)
    {
        cf[i] += cf[i-1];
        // cout<<cf[i]<<endl;
        before += cf[i]*nums[i];
    }

    sort(cf.begin(),cf.end());
    sort(nums.begin(),nums.end());

    long long after = 0;
    for(int i=n;i>=1;i--)
    {
        // cout<<cf[i+1]<<"  "<<nums[i]<<endl;
        after += cf[i+1]*nums[i];
    }

    cout<<after-before;

    return 0;
}