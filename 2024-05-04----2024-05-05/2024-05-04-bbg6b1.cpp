#include<bits/stdc++.h>
using namespace std;
vector<int> numss = {2,5,9,11,16,17,19,21,22,24,26,30,31,33,35,36,41,46,47,50,52,61};
int len = 154;
vector<vector<int>> mapp(len+1,vector<int>(len+1));
vector<int> book(110); 
int flag = 0;
bool pd(int y,int x,int nums)
{
    if(y+nums-1>len||x+nums-1>len) return false;
    for(int i=y;i<y+nums;i++)
    {
        for(int j=x;j<x+nums;j++)
        {
            if(mapp[i][j]) return false;
        }
    }
    return true;
}
void color(int y,int x,int nums)
{
    int l;
    if(nums == 0)
    {
        book[mapp[y][x]] = 0;
        l = mapp[y][x];
    }
    else{
        book[nums] = nums;
        l = nums;
    }
    for(int i = y;i < y+l;i++)
    {
        for(int j = x;j < x+l;j++)
        {
            mapp[i][j] = nums;
        }
    }
}
void dfs(int y,int x){
    if(y == len+1)
    {
        flag = 1;
        return;
    }
    if(mapp[y][x]){
        if(x == len+1)
        {
            dfs(y+1,1);
        }
        else
        {
            dfs(y,x+1);
        }
        return;
    }
    for(int i=0;i<numss.size();i++)
    {
        if(book[numss[i]])
        {
            continue;
        }
        if(!pd(y,x,numss[i]))
        {
            break;
        }
        color(y,x,numss[i]);
        if(x == len) dfs(y+1,1);
        else dfs(y,x+1);
        if(flag) return;
        color(y,x,0);
    }
}

int main(){
    color(1,1,47);
    color(1,1+47,46);
    color(1,1+47+46,61);

    dfs(1,1);

    int colorr = -1;
    for(int i = 1;i<=len;i++)
    {
        if(mapp[len][i] != colorr){
            colorr = mapp[len][i];
            cout<<colorr<<endl;
        }
    }
    
    return 0;
}