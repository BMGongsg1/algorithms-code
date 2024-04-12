#include<bits/stdc++.h>
using namespace std;
// struct State{
//     int depth;
    
// }
// int weight(int from,int to);
// vector<int> adj(int s);
vector<long long> djk(long long start,vector<vector<pair<long long,long long>>>& graph){
    long long V = graph.size();
    vector<long long> distTo(V+1,INT_MAX);
    distTo[start] = 0;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>> pq;
    pq.push({start,0});
    while(!pq.empty())
    {
        pair<long long,long long> curState = pq.top();
        pq.pop();
        long long curNodeID = curState.first;
        long long curDistFromStart = curState.second;
        cout<<curNodeID<<"  "<<curDistFromStart<<endl;
        if(curDistFromStart>distTo[curNodeID]) continue;
        for(long long i=0;i<graph[curNodeID].size();i++)
        {
            long long distToNextNode = distTo[curNodeID]+graph[curNodeID][i].second;
            if(distTo[graph[curNodeID][i].first]>distToNextNode){
                distTo[graph[curNodeID][i].first] = distToNextNode;
                pq.push({graph[curNodeID][i].first,distToNextNode});
            }
        }
    }
    vector<long long> ans;
    for(int i=0;i<V;i++)
    {
        ans.push_back(distTo[i]);
    }
    return ans;
}
int main()
{
    vector<vector<pair<long long,long long>>> edges(2022);
    for(int i =1;i<=2021;i++)
    {
        for(int j=i;j<=min(i+21,2021);j++)
        {
            edges[i].push_back({j,i/__gcd(i,j)*j});
        }
    }

    vector<long long> ans;
    ans = djk(1,edges);
    cout<<ans[2021]<<endl;
    return 0;
}