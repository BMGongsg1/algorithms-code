//统计子矩阵(70分版)
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> mapp(n+3,vector<int>(m+3));
    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<=m+1;j++)
        {
            if(i!=n+1&&j!=m+1)cin>>mapp[i][j];
            mapp[i][j]+=mapp[i-1][j]+mapp[i][j-1]-mapp[i-1][j-1];
        }
    }

    long long cnt = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int y=0;y+i<=n;y++)
            {
                for(int x=0;x+j<=m;x++)
                {
                    long long temp = mapp[i+y][j+x]-mapp[i+y][j-1]-mapp[i-1][j+x]+mapp[i-1][j-1];
                    
                    if(temp<=k)
                    {
                        // cout<<i<<"  "<<j<<"  "<<y<<"  "<<x<<"  "<<temp<<endl;
                        cnt++;
                    }
                }
            }
        }
    }

    cout<<cnt<<endl;
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {

    //     }
    // }

    return 0;
}