#include<bits/stdc++.h>
using namespace std;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int flag;
int mem[60][60];
int reach_able[60][60];
void dfs(vector<string>& mapp,int y,int x)
{
    // cout<<y<<"  "<<x<<endl;
    mem[y][x] = 1;
    if(mapp[y][x] == 'S'||mapp[y][x] == '+'||mapp[y][x] == 'T')
    {
        if(mapp[y][x] == 'T') flag = 1;
        for(int i=0;i<4;i++){
            int ay = y+dy[i],ax = x+dx[i];
            if(ay>=0&&ay<mapp.size()&&ax>=0&&ax<mapp[0].size()&&!mem[ay][ax])
            {
                if(mapp[ay][ax]=='#') continue;

                // mem[ay][ax] = 1;
                reach_able[ay][ax] = 1;
                dfs(mapp,ay,ax);
                // mem[ay][ax] = 0;
            }
        }
    }
    else if(mapp[y][x] == '|')
    {
        for(int i=0;i<2;i++){
            int ay = y+dy[i],ax = x+dx[i];
            if(ay>=0&&ay<mapp.size()&&ax>=0&&ax<mapp[0].size()&&!mem[ay][ax])
            {
                if(mapp[ay][ax]=='#') continue;

                // mem[ay][ax] = 1;
                reach_able[ay][ax] = 1;
                dfs(mapp,ay,ax);
                // mem[ay][ax] = 0;
            }
        }
    }
    else if(mapp[y][x] == '-')
    {
        for(int i=2;i<4;i++){
            int ay = y+dy[i],ax = x+dx[i];
            if(ay>=0&&ay<mapp.size()&&ax>=0&&ax<mapp[0].size()&&!mem[ay][ax])
            {
                if(mapp[ay][ax]=='#') continue;

                // mem[ay][ax] = 1;
                reach_able[ay][ax] = 1;
                dfs(mapp,ay,ax);
                // mem[ay][ax] = 0;
            }
        }
    }
    else if(mapp[y][x] == '.')
    {
            int ay = y+dy[0],ax = x+dx[0];
            if(ay>=0&&ay<mapp.size()&&ax>=0&&ax<mapp[0].size()&&!mem[ay][ax])
            {
                if(mapp[ay][ax]=='#') return;

                // mem[ay][ax] = 1;
                reach_able[ay][ax] = 1;
                dfs(mapp,ay,ax);
                // mem[ay][ax] = 0;
            }
    }
    // mem[y][x] = 0;
}

// int flag2;
bool dfs_2(vector<string>& mapp,int y,int x)
{
    bool ans = true;
    mem[y][x] = 1;
    // cout<<y<<" "<<x<<endl;
    if(mapp[y][x] == 'S'||mapp[y][x] == '+'||mapp[y][x] == 'T')
    {
        // if(mapp[y][x] == 'T') flag2 = 1;
        if(mapp[y][x] == 'S') return false;
        for(int i=0;i<4;i++){
            int ay = y+dy[i],ax = x+dx[i];
            if(ay>=0&&ay<mapp.size()&&ax>=0&&ax<mapp[0].size()&&!mem[ay][ax])
            {
                if(mapp[ay][ax]=='#') continue;

                // mem[ay][ax] = 1;
                // reach_able[ay][ax] = 1;
                ans &= dfs_2(mapp,ay,ax);
                // mem[ay][ax] = 0;
            }
        }
    }
    else if(mapp[y][x] == '|')
    {
        for(int i=0;i<2;i++){
            int ay = y+dy[i],ax = x+dx[i];
            if(ay>=0&&ay<mapp.size()&&ax>=0&&ax<mapp[0].size()&&!mem[ay][ax])
            {
                if(mapp[ay][ax]=='#') continue;

                // mem[ay][ax] = 1;
                // reach_able[ay][ax] = 1;
                ans &= dfs_2(mapp,ay,ax);
                // mem[ay][ax] = 0;
            }
        }
    }
    else if(mapp[y][x] == '-')
    {
        for(int i=2;i<4;i++){
            int ay = y+dy[i],ax = x+dx[i];
            if(ay>=0&&ay<mapp.size()&&ax>=0&&ax<mapp[0].size()&&!mem[ay][ax])
            {
                if(mapp[ay][ax]=='#') continue;

                // mem[ay][ax] = 1;
                // reach_able[ay][ax] = 1;
                ans &= dfs_2(mapp,ay,ax);
                // mem[ay][ax] = 0;
            }
        }
    }
    else if(mapp[y][x] == '.')
    {
            int ay = y+dy[0],ax = x+dx[0];
            if(ay>=0&&ay<mapp.size()&&ax>=0&&ax<mapp[0].size()&&!mem[ay][ax])
            {
                if(mapp[ay][ax]=='#') return ans;

                // mem[ay][ax] = 1;
                // reach_able[ay][ax] = 1;
                ans &= dfs_2(mapp,ay,ax);
                // mem[ay][ax] = 0;
            }
            // if(y==4&&x==4)
            // {
            //     cout<<ay<<" "<<ax<<endl;
            // }
    }
    // mem[y][x] = 0;
    return ans;
}
int main(){
    int row,col;
    cin>>row>>col;
    flag = 0;
    vector<string> mapp(row);
    for(int i=0;i<row;i++){
        cin>>mapp[i];
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(mapp[i][j] == 'S')
            {
                // mem[i][j] = 1;
                dfs(mapp,i,j);
                // mem[i][j] = 0;
            }
        }
    }

    if(!flag)
    {
        cout<<"I'm stuck!";
        return 0;
    }

    int cnt = 0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(reach_able[i][j])
            {
                // mem[i][j] = 1;
                memset(mem,0,sizeof(mem));
                if(dfs_2(mapp,i,j))
                {
                    // cout<<i<<" "<<j<<endl;
                    cnt++;
                }
                // mem[i][j] = 0;
            }
        }
    }
    cout<<cnt;

    return 0;
}