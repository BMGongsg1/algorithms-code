#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int dx[8] ={1,1,1,-1,-1,-1,0,0};
    int dy[8] ={1,0,-1,1,0,-1,1,-1}; 

    long long n,m;
    cin>>n>>m;
    vector<vector<int>> mapp(n+3,vector<int>(m+3));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mapp[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mapp[i][j]) cout<<9;
            else
            {
                int cnt = 0;
                for(int k=0;k<8;k++)
                {
                    if(mapp[i+dy[k]][j+dx[k]]) cnt++;
                }
                cout<<cnt;
            }
            if(j!=m) cout<<" ";
            else cout<<endl;
            
        }
    }

    return 0;
}