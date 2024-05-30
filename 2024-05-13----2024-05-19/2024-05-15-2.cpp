#include<bits/stdc++.h>
using namespace std;
class UF{
    int cnt;
    int* father;
public:
    UF(int num){
        this->cnt = num;
        father = new int[num+1];
        for(int i=0;i<=num;i++){
            this->father[i] = i;
        }
    }

    void union_(int a,int b)
    {
        int rootA = find(a);
        int rootB = find(b);
        if(rootA == rootB) return;
        father[rootA] = rootB;
        cnt--;
    }

    int find(int a)
    {
        if(father[a] == a) return a;
        father[a] = find(father[a]);
        return father[a];
    }

    bool pd(int a,int b)
    {
        int rootA = find(a);
        int rootB = find(b);
        return rootA == rootB;
    }

    int count_()
    {
        return cnt;
    }


};
int main(){
    int n,m,k;
    cin>>m>>n;
    vector<vector<int>> plants(n+1,vector<int>(m+1));
    int step = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            plants[i][j] = ++step;
        }
    }
    cin>>k;
    UF uf(step);
    // cout<<"ASDSDA "<<uf.count_()<<"  "<<step<<endl;
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        uf.union_(a,b);
    }

    cout<<uf.count_();

    return 0;
}