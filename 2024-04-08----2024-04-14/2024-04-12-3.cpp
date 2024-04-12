#include<bits/stdc++.h> 
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int dx[] = {-1,0,1,0};
    int dy[] = {0,-1,0,1};
    int maxx = 0,maxi = 0,maxj = 0;
    vector<vector<int>> nums(n,vector<int>(m));
    vector<vector<int>> mem(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>nums[i][j];
            if(nums[i][j]>maxx){
                maxx = nums[i][j];
                maxi = i;
                maxj = j;
            }
        }
    }

    int ans = 0;
    function<void(int ,int )> dfs = [&](int y,int x)
    {
        // cout<<y<<"  "<<x<<endl;
        ans = max(ans,mem[y][x]);
        for(int i=0;i<4;i++)
        {
            int ay = y+dy[i],ax = x+dx[i];
            if(ay>=0&&ay<n&&ax>=0&&ax<m)
            {
                if(nums[ay][ax]<nums[y][x]&&mem[y][x]>=mem[ay][ax])
                {
                    mem[ay][ax] = max(mem[ay][ax],mem[y][x]+1);
                    dfs(ay,ax);
                }
            }
        }
    };

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            dfs(i,j);
        }
    }
    cout<<ans+1;

    return 0;
}