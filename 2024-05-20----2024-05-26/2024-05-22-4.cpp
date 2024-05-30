#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long ans = 0;
    vector<vector<int>> mapp(4,vector<int>(4));
    int diry[] = {1,-1,0,0};
    int dirx[] = {0,0,1,-1};
    function<void(int,int,int)> dfs = [&](int y,int x,int index){
        if(index == 16)
        {
            ans++;
            return;
        }
            
        for(int i=0;i<4;i++)
        {
            int dy = diry[i] + y,dx = dirx[i] + x;
            if(dy<0||dy>3||dx<0||dx>3||mapp[dy][dx]) continue;
            mapp[dy][dx] = 1;
            dfs(dy,dx,index+1);
            mapp[dy][dx] = 0;
        }
    };

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            mapp[i][j] = 1;
            dfs(i,j,1);
            mapp[i][j] = 0;
        }
    }

    cout<<ans;

    return 0;
}