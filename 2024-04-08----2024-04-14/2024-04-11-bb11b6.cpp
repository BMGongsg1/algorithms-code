#include<bits/stdc++.h>
using namespace std;
// class UF{
//     private:
//     int count;
//     int *parent;
//     public:
//     UF(int n){
//         this->count = n;
//         parent = new int[n];
//         for(int i=0;i<n;i++)
//         {
//             parent[i] = i;
//         }
//     }

//     void _union(int p,int q){
//         int rootP = find(p);
//         int rootQ = find(q);

//         if(rootP==rootQ)return;
//         parent[rootQ] = rootP;
//         count--;
//     }

//     bool connected(int p,int q){
//         int rootP = find(p);
//         int rootQ = find(q);
//         return rootP == rootQ;
//     }

//     int find(int x){
//         if(parent[x] != x)
//         {
//             parent[x] = find(parent[x]);
//         }
//         return parent[x];
//     }
// };
int main()
{
    vector<vector<int>> edges(8);
    edges[1].push_back(2);
    edges[1].push_back(6);
    edges[2].push_back(1);
    edges[2].push_back(7);
    edges[2].push_back(3);
    edges[3].push_back(2);
    edges[3].push_back(7);
    edges[3].push_back(4);
    edges[4].push_back(3);
    edges[4].push_back(5);
    edges[5].push_back(4);
    edges[5].push_back(6);
    edges[5].push_back(7);
    edges[6].push_back(1);
    edges[6].push_back(7);
    edges[6].push_back(5);
    edges[7].push_back(2);
    edges[7].push_back(3);
    edges[7].push_back(5);
    edges[7].push_back(6);

    int all = 7;
    long long ans = 0;
    function<bool(int,vector<int>&)> pd = [&](int summ,vector<int>& light)->bool
    {
        int cnt =0;
        vector<int> visited(8);
        queue<int> q;
        for(int i=1;i<8;i++)
        {
            if(light[i] == 1)
            {
                q.push(i);
                visited[i] = 1;
                cnt++;
                break; 
            }
        }
        while(!q.empty())
        {
            int tp = q.front();
            q.pop();
            for(int i=0;i<edges[tp].size();i++)
            {
                if(light[edges[tp][i]] == 1&&visited[edges[tp][i]]==0)
                {
                    cnt++;
                    q.push(edges[tp][i]);
                    visited[edges[tp][i]] = 1;
                }
            }
        }
        return cnt == summ;
    };
    function<void(int,int,vector<int>&)> dfs = [&](int index,int now,vector<int>& light){
        cout<<index<<"  "<<now<<endl;
        if(index == 8)
        {
            if(now!=0&&pd(now,light))
            {
                ans++;
            }
            return;
        }
        light[index] = 1;
        dfs(index+1,now+1,light);
        light[index] = 0;
        dfs(index+1,now,light);
    };
    
    vector<int> light(8);
    light[1] = 1;
    dfs(1,1,light);
    light[1] = 0;
    dfs(1,0,light);
    cout<<ans<<endl;
    return 0;
}