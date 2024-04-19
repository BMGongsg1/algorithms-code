//2080: [蓝桥杯2023初赛] 飞机降落
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    vector<vector<vector<int>>> nums(t);
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        vector<vector<int>> temp(n,vector<int>(3));
        for(int j=0;j<n;j++)
        {
            cin>>temp[j][0]>>temp[j][1]>>temp[j][2];
        }
        nums[i] = temp;
    }
    bool bigflag = 0;

    function<void(int,int,int,int,vector<bool>&)> dfs = [&](int flag,int index,int time,int tt,vector<bool>& mapp){
        if(flag == nums[tt].size())
        {
            bigflag = 1;
        }
        // cout<<index<<"  "<<flag<<"  "<<time<<endl;
        if(bigflag) return;
        for(int i=0;i<nums[tt].size();i++)
        {
            if(mapp[i] == 0&&time<=nums[tt][i][0]+nums[tt][i][1])
            {
                mapp[i] = 1;
                if(time>=nums[tt][i][0])dfs(flag+1,i,time+nums[tt][i][2],tt,mapp);
                else dfs(flag+1,i,nums[tt][i][0]+nums[tt][i][2],tt,mapp);
                mapp[i] = 0;
            }
        }
    };
    for(int i=0;i<t;i++)
    {
        bigflag = 0;
        vector<bool> mapp(nums[i].size());
        for(int j=0;j<nums[i].size();j++)
        {
            mapp[j] = 1;
            dfs(1,j,nums[i][j][0]+nums[i][j][2],i,mapp);
            mapp[j] = 0;
        }
        if(bigflag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}