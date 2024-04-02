#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n;
    cin>>n;
    long long ma,mb;
    cin>>ma;
    vector<long long> nums1(ma);
    for(int i=0;i<ma;i++)
    {
        cin>>nums1[i];
    }
    cin>>mb;
    vector<int> weishu(ma);
    vector<long long> nums2(mb);
    for(int i=0;i<mb;i++)
    {
        cin>>nums2[i];
    }
    int a = ma-1, b = mb-1;
    while(b>=0)
    {
        weishu[a] = max(nums1[a],max(nums2[b],1LL))+1;
        a--,b--;
    }

    a = ma-1,b = mb - 1;
    while(b>=0)
    {
        nums1[a]-=nums2[b];
        if(nums1[a]<0)
        {
            nums1[a-1]--;
            nums1[a] += weishu[a];
        }
        a--;
        b--;
    }
    long long MOD = 1e9+7;
    // cout<<MOD<<endl;
    long long ans = 0;
    long long mult = 1;
    for(int i=ma-1;i>=0;i--)
    {
        // cout<<nums1[i]<<"  "<<weishu[i]<<endl;
        ans += nums1[i]*mult;
        ans%=MOD;
        mult*=weishu[i];
        mult%=MOD;
    }
    cout<<ans;

    return 0;
}