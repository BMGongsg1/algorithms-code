#include<bits/stdc++.h>
using namespace std;
class UF
{
private:
    int count;
    int *parent;
public:
    UF(int n){
        this->count = n;
        parent = new int[n];
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }
    }

    void union_(int p,int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ) return;
        parent[rootQ] = rootP;
        count--;
    }

    bool connected(int p,int q){
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    int find(int x)
    {
        if(parent[x]!=x) parent[x] = find(parent[x]);
        return parent[x];
    }
    int count_(){
        return count;
    }
};

int main(){
    
    return 0;
}