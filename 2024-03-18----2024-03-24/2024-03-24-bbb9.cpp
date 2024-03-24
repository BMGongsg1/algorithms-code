//2086: [蓝桥杯2023初赛] 砍树(用并查集做的，错了)
#include<bits/stdc++.h>
using namespace std;
class UF{
    public:
        int count;
        int* parent;
        int* size;
        UF(int n){
            this->count = n;
            parent = new int[n];
            size = new int[n];
            for(int i=0;i<n;i++)
            {
                parent[i] = i;
                size[i] = 1;
            }
        }

        void un(int rootP,int rootQ){
            
            if(rootP == rootQ) return;
            
            if(size[rootP]>size[rootQ]){
                parent[rootQ] = rootP;
                size[rootP] += size[rootQ];
            }else{
                parent[rootP] = rootQ;
                size[rootQ] += size[rootP];
            }
            
            count--;

        }
        void dele(int p,int q)
        {
            if(parent[p] == q)
            {
                parent[p] = p;
            }
            else if(parent[q] == p)
            {
                parent[q] = q;
            }
        }
        int find(int x){
            while(parent[x] != x) x = parent[x];
            return x;
        }
        bool connected(int p,int q){
            int rootP = find(p);
            int rootQ = find(q);
            return rootP == rootQ;
        }
};
int main()
{
    int n,m;
    cin>>n>>m;
    UF uf = UF(n+3);
    vector<pair<int,int>> edges(n+1);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        edges[i] = {x,y};
        uf.un(x,y);
    }
    // cout<<"ASDASDw"<<endl;
    // for(int i=n-2;i>=0;i--)
    // {
    //     cout<<uf.parent[edges[i].first]<<" p "<<uf.parent[edges[i].second]<<endl;
    // }
    vector<pair<int,int>> should_D(m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        should_D[i] = {a,b};
    }
    for(int i=n-2;i>=0;i--)
    {
        int flag = 0;
        // cout<<uf.parent[edges[i].first]<<" p "<<uf.parent[edges[i].second]<<endl;
        uf.dele(edges[i].first,edges[i].second);
        // cout<<uf.parent[edges[i].first]<<" p "<<uf.parent[edges[i].second]<<endl;
        for(int j=0;j<m;j++)
        {
            // if(i==3)
            // {
            //     cout<<uf.find(should_D[j].first)<<"  "<<uf.find(should_D[j].second)<<endl;
            // }
            if(uf.connected(should_D[j].first,should_D[j].second)){
                break;
            }    

            // cout<<"ASDASD"<<endl;
            flag++;
        }
        if(flag == m){
            cout<<i+1;
            return 0;
        }
        uf.un(edges[i].first,edges[i].second);

    }
    return 0;
}