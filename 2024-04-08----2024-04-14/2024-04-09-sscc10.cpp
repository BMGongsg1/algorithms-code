#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long MOD = 1e9+7;
    vector<long long> nums(n);
    for(int i=0;i<nums.size();i++)
    {
        cin>>nums[i];
    }

    sort(nums.begin(),nums.end());
    auto qpow = [&](int x,int b)->long long{
        long long ans = 1;
        while(b)
        {
            if(b&1)
            {
                ans*=x;
                ans%=MOD;
            }
            x*=x;
            x%=MOD;
            b>>=1;
        }
        return ans;
    };
    long long ans = 0;
    for(int i=nums.size()-2;i>=0;i--)
    {
        long long last = nums[nums.size()-1];
        if(nums[i] == 1)
        {
            ans+=qpow(last,nums[i]);
        }
        else ans += qpow(nums[i],last);
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}