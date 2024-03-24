//2086: [蓝桥杯2023初赛] 砍树
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> edges(n+1);
    vector<int> deep(n+1);
    vector<vector<int>> dp(n+1,vector<int>(22));
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        edges[x].push_back({y,i});
        edges[y].push_back({x,i});
    }
    function<void(int,int)> dfs = [&](int node,int father){
        deep[node] = deep[father] +1;
        dp[node][0] = father;
        for(int i=1;i<=20;i++)
        {
            dp[node][i] = dp[dp[node][i-1]][i-1];
        }
        for(int i=0;i<edges[node].size();i++)
        {
            if(edges[node][i].first==father) continue;
            dfs(edges[node][i].first,node);
        }
        return;
    };

    function<int(int,int)> lca = [&](int x,int y)->int
    {
        if(deep[x]<deep[y]) swap(x,y);
        int dd = deep[x]-deep[y];
        for(int i=20;i>=0;i--)
        {
            if(deep[dp[x][i]]>=deep[y])
            {
                x = dp[x][i];
            }
        }
        if(x==y) return x;
        for(int i=20;i>=0;i--)
        {
            if(dp[x][i]!=dp[y][i])
            {
                x = dp[x][i];
                y = dp[y][i];
            }
        }
        return dp[x][0];
    };

    vector<int> d(n+1);
    int ans = -1;
    function<void(int,int)> get = [&](int x,int y){
        for(int i=0;i<edges[x].size();i++)
        {
            if(edges[x][i].first == y) continue;
            get(edges[x][i].first,x);
            d[x]+=d[edges[x][i].first];
        }
        for(auto [v,id]:edges[x])
        {
            if(d[x]==m&&d[v]==m) ans = max(ans,id);
        }
    };
    dfs(1,0);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        int LCA = lca(x,y);
        d[x]++,d[y]++,d[LCA]--,d[dp[LCA][0]]--;
    }
    get(1,0);
    cout<<ans;

    return 0;
}