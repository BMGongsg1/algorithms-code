#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<vector<int>> edges(N+1);
    vector<int> du(N+1);
    for(int i=0;i<N;i++)
    {
        int from,to;
        cin>>from>>to;
        du[from]++;
        du[to]++;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    queue<int> q;
    for(int i=0;i<=N;i++)
    {
        if(du[i] == 1) q.push(i);
    }

    while(!q.empty()){
        int tp = q.front();
        q.pop();
        for(int i=0;i<edges[tp].size();i++)
        {
            int to = edges[tp][i];
            du[to]--;
            if(du[to] == 1)
            {
                q.push(to);
            }
        }
    }

    for(int i=0;i<=N;i++)
    {
        if(du[i]>1) cout<<i<<" ";
    }


    // unordered_set<int> sett;
    // int flag = 0,start = 0;
    // function<void(int,int)> dfs = [&](int index,int fa)
    // {
    //     // cout<<index<<"  "<<fa<<"  "<<start<<endl;
    //     if(flag) return;
    //     for(int i=0;i<edges[index].size();i++)
    //     {
    //         int to = edges[index][i];
    //         if(fa == to) continue;
    //         if(sett.find(to)!=sett.end()&&start==0){
    //             // cout<<"complete "<<index<<"  "<<to<<endl;
    //             flag = 1;
    //             start = to;
    //             break;
    //         }
    //         sett.insert(to);
    //         dfs(to,index);
    //     }
    // };

    // sett.insert(1);
    // dfs(1,-1);

    // vector<int> temp;
    // vector<int> ans;
    // function<void(int,int)> dfss = [&](int index,int fa){
    //     if(fa!=-1&&index == start)
    //     {
    //         ans = temp;
    //         return;
    //     }

    //     for(int i=0;i<edges[index].size();i++)
    //     {
    //         int to = edges[index][i];
    //         if(fa == to) continue;
    //         temp.push_back(to);
    //         dfss(to,index);
    //         temp.pop_back();
    //     }

    // };

    // dfss(1,-1);

    // sort(ans.begin(),ans.end());
    
    // for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}