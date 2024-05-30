#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m;
    cin>>n>>m;
    vector<vector<long long>> mapp(n,vector<long long>(n));
    for(int i=0;i<m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        mapp[a][b] = c;
        mapp[b][a] = c;
    }

    

    return 0;
}