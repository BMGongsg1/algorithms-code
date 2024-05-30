#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n,k;
int deep[N];
vector<vector<int>> edges;
vector<vector<int>> weight;
long long path[N];
long long dist[N];

void dfs(int u,int father)
{
    deep[u] = deep[father]+1;
    dp[u][0] = father;
    for(int i=1;i<=20;i++)
    {
        dp[u][i] = dp[dp[u][i-1]][i-1];
    }
    for(int i=0;i<edges[u].size();i++)
    {
        int v = edges[u][i],w = weight[u][i];
        if(v==father) continue;
        dist[v] = dist[u]+w;
        dfs(v,u);
    }
}

int LCA(int x,int y)
{
    if(deep[x]<deep[y]) swap(x,y);
    for(int i=20;i>=0;i--)
    {
        if(deep[dp[x][i]]>=deep[y])
        {
            x = dp[x][i];
        }
    }
    if(x == y) return x;
    for(int i=20;i>=0;i--)
    {
        if(dp[x][i] != dp[y][i])
        {
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    return dp[x][0];
}

long long get_dist(int x,int y)
{
    if(x==0||y==0) return 0;
    return dist[x]+dist[y]-2*dist[LCA(x,y)];
}

int main()
{
    return 0;
}