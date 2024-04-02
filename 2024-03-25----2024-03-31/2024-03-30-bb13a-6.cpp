//最长上升子序列(未完成)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    long long n,k;
    cin>>n>>k;
    vector<vector<int>> dp(n+1,vector<int>(2));
    vector<int> nums(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    int end1 = 0,end2 = k;
    dp[0][0] = nums[0];
    dp[k][1] = nums[0]; 
    for(int i=1;i<n;i++)
    {
        if(nums[i]>=nums[i-1])
        {
            end1++;
            end2++;
            dp[end1][0] = nums[i];
            dp[end2][1] = nums[i];
        }
        else{
            //之前都没变过
            int left = 0,right = end1;
            while(left<=right)
            {
                int mid = left+(right-left)/2;
                if(dp[mid][0]>nums[i])
                {
                    right = mid-1;
                }
                else
                {
                    left = right+1;
                }
            }
            dp[left][0] = nums[i];
            dp[left+k][1] = nums[i];

            //之前变过
            int left = 0,right = end2;
            while(left<=right)
            {
                int mid = left+(right-left)/2;
                if(dp[mid][1]>nums[i])
                {

                }
            }
        }
    }

    return 0;
}