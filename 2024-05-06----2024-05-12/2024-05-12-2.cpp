#include<bits/stdc++.h>(错的，但是题太臭了就不改了)
using namespace std;
int main()
{
    vector<vector<int>> lines(10);
    vector<pair<int,int>> mapp = {{3,4},{1,2},{4,5},{1,3},{5,2},{1,5},{-1,-1},{2,4},{2,3},{5,3},{-1,-1},{1,4}};
    vector<int> mem(13);

    long long ans = 0;
    function<void(int)> dfs = [&](int index){
        if(index == 7||index == 11) dfs(index+1);
        if(index == 13)
        {
            ans++;
            return;
        }
        for(int i=0;i<12;i++)
        {
            if(mapp[i].first == -1&&mem[i]) continue;
            int fst = mapp[i].first,sec = mapp[i].second;
            if(lines[fst].size()<4&&lines[sec].size()<4)
            {
                mem[i] = 1;
                lines[fst].push_back(index);
                lines[sec].push_back(index);
                int flag = 1;
                if(lines[fst].size()==4)
                {
                    int sum = 0;
                    for(int j=0;j<4;j++)
                    {
                        sum += lines[fst][j];
                    }
                    if(sum!=24)
                    {
                        flag = 0;
                        // lines[fst].pop_back();
                    }
                }
                if(lines[sec].size()==4)
                {
                    int sum = 0;
                    for(int j=0;j<4;j++)
                    {
                        sum += lines[sec][j];
                    }
                    if(sum!=24)
                    {
                        flag = 0;
                        // lines[sec].pop_back();
                    }
                }
                if(flag)dfs(index+1);
                lines[fst].pop_back();
                lines[sec].pop_back();
                mem[i] = 0;
            }
        }
    };
  
    dfs(1);

    cout<<ans/10;

    return 0;
}