//2105: [蓝桥杯2023初赛] 棋盘
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio;
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> mapp(n+3,vector<int>(n+3,0));
    for(int i=0;i<m;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        mapp[x1][y1]+=1;
        mapp[x1][y2+1]-=1;
        mapp[x2+1][y1]-=1;
        mapp[x2+1][y2+1]+=1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            mapp[i][j]+=mapp[i][j-1]+mapp[i-1][j]-mapp[i-1][j-1];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(abs(mapp[i][j]%2==0))
            {
                cout<<0;
            }
            else
            {
                cout<<1;
            }
        }
        cout<<endl;
    }

    return 0;
}