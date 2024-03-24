//2070: [蓝桥杯2023初赛] 更小的数
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long ans = 0;
    string nums;
    cin>>nums;
    for(int i=1;i<nums.size()-1;i++)
    {
        int left = i-1,right = i+1;
        int flag = 0;
        while(left>=0&&right<nums.size())
        {
            if(nums[left] == nums[right]&&flag == 0)
            {
                flag = 0;
            }
            else if(nums[left] > nums[right])
            {
                flag = 1;
            }
            else if(nums[left] < nums[right])
            {
                flag = -1;
            }
            if(flag == 1) ans++;
            left--;
            right++;
        }
    }
    for(int i=0;i<nums.size()-1;i++)
    {
        int left = i,right = i+1;
        int flag = 0;
        while(left>=0&&right<nums.size())
        {
            if(nums[left] == nums[right]&&flag == 0)
            {
                flag = 0;
            }
            else if(nums[left] > nums[right])
            {
                flag = 1;
            }
            else if(nums[left] < nums[right])
            {
                flag = -1;
            }
            if(flag == 1) ans++;
            left--;
            right++;
        }
    }
    cout<<ans;
    return 0;
}