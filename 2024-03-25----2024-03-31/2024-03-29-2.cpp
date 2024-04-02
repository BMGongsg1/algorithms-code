#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> edges(n+1);
    vector<int> deep(n+1);
    vector<vector<int>> dp(n+1,vector<int>(22));
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    function<void(int,int)> dfs = [&](int node,int father){
        deep[node] = deep[father]+1;
        dp[node][0] = father;
        for(int i=0;i<=20;i++)
        {
            dp[node][i] = dp[dp[node][i-1]][i-1];
        }
        for(int i=0;i<edges[node].size();i++)
        {
            if(edges[node][i].first == father) continue;
            dfs(edges[node][i].first,node);
        }
    }

    function<int(int,int)> lca = [&](int x,int y)->int {
        if(deep[x]<deep[y]) swap(x,y);
        for(int i=20;i>=0;i--){
            if(deep[dp[x][i]]>=deep[y])
            {
                x = dp[x][i];
            }
        }
        if(x==y) continue;
        for(int i=20;i>0;i--)
        {
            if(dp[x][i]!=dp[y][i])
            {
                x = dp[x][i];
                y = dp[y][i];
            }
        }
        return dp[x][0];
    }

    dfs(1,0);


    return 0;
}