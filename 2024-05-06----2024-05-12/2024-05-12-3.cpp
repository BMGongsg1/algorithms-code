#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int stx,sty,edx,edy;
    vector<vector<int>> mapp(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char temp;
            cin>>temp;
            if(temp == '+') mapp[i][j] = 1;
            else if(temp == '-') mapp[i][j] = 0;
            else if(temp == 'A') 
            {
                sty = i;
                stx = j;
                mapp[i][j] = 2;
            }
            else if(temp == 'B'){
                edy = i;
                edx = j;
                mapp[i][j] = 3;
            }
        }
    }
    // vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(n,vector<long long>(3,INT_MAX)));
    vector<vector<long long>> dp(n,vector<long long> (n,INT_MAX));

    dp[sty][stx] = 0;
    int diry[] = {1,-1,0,0};
    int dirx[] = {0,0,1,-1};

    function<void(int,int)> dfs = [&](int y,int x){
        for(int i=0;i<4;i++){
            int dy = y+diry[i],dx = x+dirx[i];
            if(dy<0||dy>=n||dx<0||dx>=n) continue;
            if(mapp[y][x]!=mapp[dy][dx])
            {
                if(dp[y][x]+1<dp[dy][dx])
                {
                    dp[dy][dx] = dp[y][x]+1;
                    dfs(dy,dx);
                }
            }
        }
    };

    dfs(sty,stx);

    cout<<dp[edy][edx]<<endl;
    
    return 0;
}