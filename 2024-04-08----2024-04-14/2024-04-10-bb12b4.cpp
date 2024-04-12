#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long ans = 0;
    long long num = 2021041820210418;

    function<long long(long long,long long)> dfs = [&](long long nums,long long index)->long long{
        if(index == 2) return 1;
        long long ans = 0;
        for(long long i=1;i*i<=nums;i++)
        {
            if(nums%i == 0)
            {
                if(nums/i!=i)ans+=dfs(nums/i,index+1)+dfs(i,index+1);
                else ans+=dfs(i,index+1);
            }
        }
        return ans;
    };
    cout<<dfs(num,0);

    // 下面是递归解
    // vector<long long> nums;
    // for(long long i=1;i*i<=num;i++)
    // {
    //     if(num%i==0)
    //     {
    //         nums.push_back(i);
    //         if(num/i!=i)
    //         {
    //             nums.push_back(num/i);
    //         }
    //     }
    // }

    // for(long long i=0;i<nums.size();i++)
    // {
    //     for(long long j=0;j<nums.size();j++)
    //     {
    //         for(long long k=0;k<nums.size();k++)
    //         {
    //             if(nums[i]*nums[j]*nums[k]==num) ans++;
    //         }
    //     }
    // }
    // cout<<ans;


    return 0;
}