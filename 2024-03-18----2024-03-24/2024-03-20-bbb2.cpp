//2078: [蓝桥杯2023初赛] 01 串的熵
#include<bits/stdc++.h>
using namespace std;
int main()
{
    for(double i=0;i<23333333/2;i++)
    {
        double sum = 0;
        sum-=(i*(i/23333333))*log2(i/23333333)+((23333333-i)*(23333333-i)/23333333)*log2((23333333-i)/23333333);
        // if(sum>11600000) cout<<sum<<endl;
        if(sum>11625907.5&&sum<11625907.6)
        {
            cout<<(int)i<<endl;
        }
    }
    return 0;
}