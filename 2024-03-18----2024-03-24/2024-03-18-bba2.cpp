//2068: [蓝桥杯2023初赛] 有奖问答
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0;
    int m = 0;
    function<void(int,int)> dfs = [&](int index,int score)
    {
        if(index == 30)
        {
            n++;
            if(score == 70) m++;
            return;
        }
        if(score == 100)
        {
            n++;
            return;
        }
        if(score==70) m++; 
        dfs(index+1,score+10);
        dfs(index+1,0);
    };
    dfs(0,0);
    cout<<m<<endl;
    return 0;
}