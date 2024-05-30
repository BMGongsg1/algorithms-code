#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> mapp(3,vector<int>(3));

    // int diry[] = {1,-1,0,0};
    // int dirx[] = {0,0,1,-1};

    int ans = 0;

    function<bool()> pd = [&]()->bool{
        unordered_set<int> sett;
        for(int i=0;i<3;i++)
        {
            int line = 0;
            int col = 0;
            for(int j=0;j<3;j++){
                line += mapp[i][j];
                col += mapp[j][i];
            }
            sett.insert(line);
            sett.insert(col);
        }

        int temp = 0;
        for(int i=0;i<3;i++) temp +=  mapp[i][i];
        sett.insert(temp);
        temp = 0;
        for(int i=0;i<3;i++) temp += mapp[i][2-i];
        sett.insert(temp);
        if(sett.size() == 8)
        {
            // cout<<"ASDSAD"<<endl;
            // for(auto a:sett)
            // {
            //     cout<<a<<" ";
            // }
            // cout<<endl;
        }
        return sett.size() == 8;
    };

    function<void(int)> dfs = [&](int index)
    {
        if(index == 10)
        {
            // cout<<"ASDSAD"<<endl;
            if(pd()){ans++;
                // for(int i=0;i<3;i++)
                // {
                //     for(int j=0;j<3;j++)
                //     {
                //         cout<<mapp[i][j]<<" ";
                //     }
                //     cout<<endl;
                // }
                // cout<<endl<<endl;
            }
            return;
        }
        // cout<<index<<endl;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(mapp[i][j]) continue;
                mapp[i][j] = index;
                dfs(index+1);
                mapp[i][j] = 0;
            }
        }
    };

    dfs(1);

    cout<<ans/8<<" "<<45360*8<<endl;

    return 0;
}