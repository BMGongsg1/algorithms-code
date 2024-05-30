#include<bits/stdc++.h>
using namespace std;
int main(){
    long long num,A,B;
    cin>>num>>A>>B;
    int len = 0;
    long long temp = num;
    while(temp)
    {
        len++;
        temp/=10;
    }
    vector<long long> nums(len+1);
    temp = num;
    int step = 0;
    while(temp)
    {
        nums[step++] = temp%10;
        temp/=10;
    }
    vector<vector<vector<long long>>> dp(len+1,vector<vector<long long>>(A+1,vector<long long>(B+1)));

    long long ans = 0;
    vector<long long> pre(len+1);
    pre[0] = nums[0];
    for(int i=1;i<=len;i++)
    {
        pre[i] = pre[i-1]*10+nums[i];
    }
    function<void(int,int,int,long long)> dfs = [&](int index,int a,int b,long long now_num){
        if(now_num<=dp[index][a][b]&&now_num!=0) return;
        if(index == len)
        {
            ans = max(ans,now_num);
            return;
        }

        dp[index][a][b] = now_num;
        ans = max(ans,now_num+pre[len-index-1]);
        // cout<<index<<" "<<a<<" "<<b<<" "<<now_num<<endl;
        if(9-nums[len-index-1]<=a) {
            dfs(index+1,a-(9-nums[len-index-1]),b,now_num*10+9);
        }
        else 
        {
            // cout<<"a else "<<index<<" "<<a<<" "<<b<<" "<<nums[len-index-1]<<" "<<now_num*10+nums[len-index-1]+a<<endl;
            dfs(index+1,0,b,now_num*10+nums[len-index-1]+a);
        }
        if(nums[len-index-1]+1<=b)
        {
            dfs(index+1,a,b-(nums[len-index-1]+1),now_num*10+9);
        }
        else
        {
            dfs(index+1,a,b,now_num*10+nums[len-index-1]);
        }
    };

    dfs(0,A,B,0LL);
    cout<<ans;

    return 0;
}