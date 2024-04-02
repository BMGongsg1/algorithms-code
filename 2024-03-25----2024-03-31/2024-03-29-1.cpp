//P5908 猫猫和企鹅
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d;
    cin>>n>>d;
    vector<vector<int>> edges(n+1);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    vector<int> vi(n+1);
    vi[1] = 1;
    queue<int> q;
    q.push(1);
    int step = 0;
    int ans = 0;
    while(!q.empty()&&step<d)
    {
        int sz = q.size();
        for(int i=0;i<sz;i++)
        {
            int temp = q.front();
            for(int j=0;j<edges[temp].size();j++)
            {
                if(vi[edges[temp][j]]==0){q.push(edges[temp][j]);ans++;vi[edges[temp][j]]=1;}
                
            }
            q.pop();
        }
        step++;
    }
    cout<<ans<<endl;

    return 0;
}