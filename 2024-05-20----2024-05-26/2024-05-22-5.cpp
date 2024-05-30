#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long k;
    cin>>k;
    long long x1,y1,x2,y2;
    cin>>x1>>y1;
    cin>>x2>>y2;
    int mapp[][3] = {{1,6,7},{2,5,8},{3,4,9}};
    // for(int i=0;i<3;i++)
    // {
    //     for(int j=0;j<3;j++)
    //     {
    //         cout<<mapp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    long long indexp1 = 0,indexp2 = 0;

    function<long long(long long,long long,long long)> dfs = [&](long long y,long long x,long long kk)->long long{
        if(kk == 1) return mapp[y][x];
        long long tempy = y, tempx = x;
        for(int i=0;i<kk-1;i++)
        {
            tempy/=3;
            tempx/=3;
        }

        long long num = 1;
        for(int i=0;i<kk-1;i++)
        {
            num*=9;
        }

        long long tempsum;
        long long limit = pow(3,kk-1);
        long long nxty = y%limit,nxtx = x%limit;

        if(mapp[tempy][tempx]%2 == 1)
        {
            tempsum = dfs(nxty,nxtx,kk-1);
        }
        else
        {
            tempsum = dfs(nxty,limit-(nxtx)-1,kk-1);
        }

        // cout<<num<<" "<<nxty<<" "<<nxtx<<"  "<<tempy<<" "<<tempx<<" "<<mapp[tempy][tempx]<<" "<<tempsum<<endl;

        return num*(mapp[tempy][tempx]-1)+tempsum;
    };

    // cout<<mapp[1][2]

    indexp1 = dfs(y1,x1,k);
    indexp2 = dfs(y2,x2,k);

    cout<<abs(indexp2-indexp1)<<endl;

    return 0;
}