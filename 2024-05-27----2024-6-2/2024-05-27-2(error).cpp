#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,m;
    cin>>n>>m>>k;
    int mo[13] = [0,0,31,28,31,30,31,30,31,31,30,31,30];
    vector<int> pre(13);
    for(int i=1;i<=12;i++) pre[i] = pre[i-1] + mo[i];
    vector<vector<int>> nums(n+1,vector<int>(2));
    for(int i=0;i<n;i++){
        int month,d,v;
        cin>>month>>d>>v;
        d += pre[month];
        nums[i][0] = d;
        nums[i][1] = v;
    }

    vector<vector<vector<int>>> dp(365+1,vector<vector<int>>(m+1,vector<int>(2)));
    for(int i=0;i<n;i++)
    {
        if(nums[i][1]<=m) dp[nums[i][0]][nums[i][1]][1] = 1;
        dp[nums[i][0]][0] = 1; 
    }

    for(int i=1;i<=365;i++)
    {
        for(int j=i-k;j>=1;j--)
        {
            for(int p=m;p>=0;p--)
            {
                dp[i][m]
            }
        }
    }

    return 0;
}