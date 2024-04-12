#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    long long n;
    cin>>n;

    vector<long long> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    vector<long long> dp(n+1);
    dp[0] = 8;
    for(int i=0;i<n;i++){
        dp[i] = nums[i];
        for(int j=i-1;j>=0;j--)
        {
            if(nums[i]>nums[j])
            {
                dp[i] = max(dp[i],dp[j]+nums[i]);
            }
        }
    }

    long long maxx = 0;
    for(int i=0;i<n;i++)
    {
        // cout<<dp[i]<<endl;
        maxx = max(dp[i],maxx);
    }

    //不能使用最长子序列的做法，要用傻逼法
    // vector<long long> dp(1);
    // dp[0] = 0; 
    // for(int i=1;i<n;i++)
    // {
    //     if(nums[i]>nums[dp[dp.size()-1]])
    //     {
    //         dp.push_back(i);
    //     }
    //     else
    //     {
    //         int left = 0,right = dp.size()-1;
    //         while(left<=right)
    //         {
    //             cout<<left<<"  "<<right<<endl;
    //             int mid = left + (right-left>>1);
    //             if(nums[dp[mid]]<nums[i])
    //             {
    //                 left = mid + 1;
    //             }
    //             else{
    //                 right = mid - 1;
    //             }
    //         }
    //         dp[left] = i;
    //     }
    // }

    // long long ans = 0;
    // for(int i=0;i<dp.size();i++)
    // {
    //     cout<<dp[i]<<endl;
    //     ans += nums[dp[i]];
    // }
    cout<<maxx;

    return 0;
}