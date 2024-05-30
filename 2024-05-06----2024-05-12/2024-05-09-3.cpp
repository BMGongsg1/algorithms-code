#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans = 0;
    vector<vector<int>> mapp(7,vector<int>(7));
    int diry[4] = {0,0,-1,1};
    int dirx[4] = {-1,1,0,0};
    function<void(int,int,int)> dfs = [&](int y,int x,int len){
        if(len>12) return;
        if(y==0&&x==0&&len>=4)
        {
            ans++;
            return;
        }
        // cout<<y<<" "<<x<<" "<<len<<endl;
        for(int i=0;i<4;i++){
            int dy = y+diry[i],dx = x+dirx[i];
            if(dy<0||dy>5||dx<0||dx>5) continue;
            if(mapp[dy][dx]) continue;
            mapp[dy][dx] = 1;
            dfs(dy,dx,len+1);
            mapp[dy][dx] = 0;
        }
    };

    dfs(0,0,0);

    cout<<ans;

    return 0;
}