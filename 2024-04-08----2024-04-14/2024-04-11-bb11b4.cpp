#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> nums(1000,vector<int>(1000));
    int cnt = 1,y=0,x=0,flag = 0;
    nums[0][0] = 1;
    while(cnt<100000)
    {
        if(y==0)
        {
            flag = 0;
            cnt++;
            x++;
            nums[y][x] = cnt;
        }
        while(x>0)
        {
            cnt++;
            x--;
            y++;
            nums[y][x] = cnt;
        }
        if(x == 0)
        {
            flag = 1;
            cnt++;
            y++;
            nums[y][x] = cnt;
        }
        while(y>0)
        {
            cnt++;
            y--;
            x++;
            nums[y][x] = cnt;
        }
    }
    cout<<nums[2][2]<<endl;
    cout<<nums[19][19]<<endl;
    return 0;
}