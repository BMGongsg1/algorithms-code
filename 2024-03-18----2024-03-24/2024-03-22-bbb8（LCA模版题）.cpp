//2085: [蓝桥杯2023初赛] 景区导游(LCA模版题)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<vector<pair<int,int>>> edges(n+1);
    vector<long long> dist(n+1);
    vector<vector<int>> dp(n+1,vector<int>(22));
    vector<int> deep(n+1);

    for(int i=1;i<=n-1;i++)
    {
        int u,v,t;
        cin>>u>>v>>t;
        edges[u].push_back({v,t});
        edges[v].push_back({u,t});
    }

    function<void(int,int)> dfs = [&](int node,int father)
    {
        deep[node] = deep[father]+1;
        dp[node][0] = father;
;        for(int i=1;i<=20;i++)
        {
            dp[node][i] = dp[dp[node][i-1]][i-1];
        }
        
        for(int i=0;i<edges[node].size();i++)
        {
            if(edges[node][i].first == father) continue;
            dist[edges[node][i].first] = dist[node]+edges[node][i].second;
            dfs(edges[node][i].first,node);
        }
        return;
    };


    function<int(int,int)> lca = [&](int x,int y)->int
    {
        if(deep[x]<deep[y]) swap(x,y);
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

    dfs(1,0);
    long long sum=0;
    vector<long long> path(k+3);

    auto get_dis = [&](int x,int y) -> long long
    {
        if(x==0||y==0) return 0;
        return dist[x]+dist[y]-2*dist[lca(x,y)];
    };

    vector<long long> diss(k+3);
    for(int i=1;i<=k;i++)
    {
        cin>>path[i];
        diss[i] = get_dis(path[i],path[i-1]);
        sum += diss[i];
    }
    diss[k+1] = get_dis(path[k],path[k+1]);
    
    // cout<<sum<<endl;
    for(int i=1;i<=k;i++)
    {
        long long dist1 = diss[i];
        long long dist2 = diss[i+1];
        long long dist3 = get_dis(path[i-1],path[i+1]);
        cout<<sum-dist1-dist2+dist3<<" ";
    }

    return 0;
}