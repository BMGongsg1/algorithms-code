//2067: [蓝桥杯2023初赛] 幸运数
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0;
    for(int i=1;i<=100000000;i++)
    {
        int temp = i;
        int step = 0;
        while(temp)
        {
            temp/=10;
            step++;
        }
        if(step%2!=0) continue;
        temp = i;
        int before = 0,af = 0;
        int now_step = 0;
        while(temp)
        {
            if(now_step*2>=step)
            {
                af+=temp%10;
            }
            else
            {
                before+=temp%10;
            }
            now_step++;
            temp/=10;
        }
        if(before == af) n++;
    }
    cout<<n<<endl;
    return 0;
}