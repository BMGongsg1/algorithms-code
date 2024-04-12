#include<bits/stdc++.h>//(第一次错错在pp里面参数没有用long long)
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long MOD = 1e9+7;
    long long n,k;
    cin>>n>>k;

    vector<long long> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    sort(nums.begin(),nums.end());

    auto pp = [&](long long x,long long b)->long long{
        long long ans = 1;
        while(b){
            if(b&1)
            {
                ans = (ans*x)%MOD; 
            }
            x = (x*x)%MOD;
            b>>=1;
        }
        return ans;
    };
	
//	cout<<pp(2,100000)<<endl;
    vector<long long> pre(100005);
    pre[0] = 1;
    for(int i=1;i<pre.size();i++)
    {
        long long temp = pp(2,i-1);
        pre[i] = (pre[i-1] + temp)%MOD;
    }
//    for(int i=0;i<nums.size();i++)
//    {
//        cout<<pre[i]<<" ";
//    }
//    cout<<endl;

    long long ans = 0;
    long long temp = 1;
    for(int i=nums.size()-1;i>=0;i--)
    {
        // int fflag = 0;
        // if(i>0)
        // {
        //     if(nums[i]==nums[i-1])
        //     {
        //         temp++;
        //         continue;
        //     }
            
        // }
        auto indexx = upper_bound(nums.begin(),nums.end(),k-nums[i]);
        int index = distance(nums.begin(),indexx);
        index -= 1;
        int flag = 0;
        // cout<<index<<"  ";
        if(nums[i]+nums[index]>k) flag = 1;
        if(!flag)
        {
            if(index>=i)
            {
                ans += pre[i];
            }
            else
            {
                ans += (pre[i]-pre[i-index-1]);
            }
        }
        ans%=MOD;
        // cout<<index<<"  ";
        temp = 1;
    }
    // cout<<endl;
    cout<<ans%MOD;
    // long long leftt = 0,rightt = 0;
    // long long ans = 0;
    // while(rightt<n)
    // {
    //     // cout<<rightt<<"  "<<leftt<<endl;
    //     while(rightt<n&&(nums[rightt]+nums[leftt]<=k))
    //     {
    //         ans+=pow(2,rightt-leftt);
    //         cout<<ans<<"  "<<rightt<<"  "<<leftt<<endl;
    //         ans%=MOD;
    //         rightt++;
    //     }
    //     if(left == right) 
    //     if(rightt>=n) break;
    //     while(leftt<rightt&&nums[rightt]+nums[leftt]>k)
    //     {
    //         leftt++;
    //     }
    // }
    // cout<<ans;

    return 0;
}