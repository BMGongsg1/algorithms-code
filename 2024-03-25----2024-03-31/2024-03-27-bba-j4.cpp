//2103: [蓝桥杯2023初赛] 特殊日期(是4年一个闰，但是100的倍数不是，400的倍数是)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> date={{31,29,31,30,31,30,31,31,30,31,30,31},{31,28,31,30,31,30,31,31,30,31,30,31},{31,28,31,30,31,30,31,31,30,31,30,31},{31,28,31,30,31,30,31,31,30,31,30,31}};
    long long cnt = 1;
    // cout<<date[3][1]<<endl;
    for(int i=2000;i<2000000;i++)
    {
        for(int j=1;j<=12;j++)
        {
            int flag = 0;
            if(j==2&&((i%4 == 0&&i%100!=0)||i%400==0)) flag = 1;
            for(int k=1;k<=(flag==0?date[1][j-1]:29);k++)
            {
                if(i%j==0&&i%k==0)
                {
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}