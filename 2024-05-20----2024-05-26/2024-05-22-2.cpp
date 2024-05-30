#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 2020;
    vector<vector<int>> mapp(n*20+1,vector<int>(n*20+1));
    int diry[] = {-1,1,0,0};
    int dirx[] = {0,0,1,-1};
    
    long long mini = 0 , cnt = 0;

    queue<pair<int,int>> q;
    q.push({0+5000,0+5000});
    q.push({2020+5000,11+5000});
    q.push({11+5000,14+5000});
    q.push({2000+5000,2000+5000});
    mapp[0+5000][0+5000] = 1;
    mapp[2020+5000][11+5000] = 1;
    mapp[11+5000][14+5000] = 1;
    mapp[2000+5000][2000+5000] = 1;

    while(mini<=2020){
        long long sz = q.size();
        cnt += sz;
        for(int i=0;i<sz;i++){
            auto tp = q.front();
            q.pop();
            int y = tp.first, x = tp.second;
            for(int j=0;j<4;j++){
                int dy = y+diry[j],dx = x+dirx[j];
                if(mapp[dy][dx] == 0)
                {
                    mapp[dy][dx] = 1;
                    q.push({dy,dx});
                }
            }
        }
        mini++;
    }

    cout<<cnt;

    return 0;
}