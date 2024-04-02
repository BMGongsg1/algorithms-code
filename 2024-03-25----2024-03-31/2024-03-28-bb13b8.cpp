//扫雷(没debug出来的版本)
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
    vector<vector<int>> lei(3,vector<int>(m+2));
    for(int i=1;i<=m;i++)
    {
        cin>>lei[1][i];
    }
    for(int i=2;i<=n+1;i++)
    {
        lei[(i-2)%3].resize(m+2,0);
        for(int j=1;j<=m;j++)
        {
            if(i<=n)cin>>lei[i%3][j];
            if(j!=1)
            {
                if(lei[(i-1)%3][j-1]==1) cout<<9<<" ";
                else
                {
                    int cnt = 0;
                    for(int k=0;k<8;k++)
                    {
                        if(lei[(i-1+dy[k])%3][j-1+dx[k]]==1) {cnt++;
                            if(i==4){
                        cout<<endl<<(i-1+dy[k])%3<<"  "<<j-1+dx[k]<<endl;
                    }
                        }
                    }
                    cout<<cnt<<" ";
                }
            }
        }
        if(lei[(i-1)%3][m]==1) cout<<9<<endl;
        else
        {
            int cnt = 0;
            for(int k=0;k<8;k++)
            {
                if(lei[(i-1+dy[k])%3][m+dx[k]]==1){
                    cnt++;
                    if(i==4){
                        cout<<endl<<(i-1+dy[k])%3<<"  "<<m+dx[k]<<endl;
                    }
                }
            }
            cout<<cnt<<endl;
        }
    }
    // if(lei[(n)%3][m]==1) cout<<9<<endl;
    // else
    // {
    //     int cnt = 0;
    //     for(int k=0;k<8;k++)
    //     {
    //         if(lei[(n+dy[k])%3][m+dx[k]]==1) cnt++;
    //     }
    //     cout<<cnt<<endl;
    // }

    return 0;
}