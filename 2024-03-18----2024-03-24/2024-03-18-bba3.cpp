//2069: [蓝桥杯2023初赛] 平方差
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> duizhao1(10);
    vector<int> duizhao2(10);
    vector<int> duizhao3(10);
    vector<int> duizhao4(10);
    duizhao1[1] = 1;
    duizhao1[2] = 2;
    duizhao1[3] = 2;
    duizhao1[4] = 3;
    duizhao1[5] = 4;
    duizhao1[6] = 5;
    duizhao1[7] = 5;
    duizhao1[8] = 6;
    duizhao1[9] = 7;

    duizhao2[2] = 1;
    duizhao2[3] = 2;
    duizhao2[4] = 3;
    duizhao2[5] = 3;
    duizhao2[6] = 4;
    duizhao2[7] = 5;
    duizhao2[8] = 6;
    duizhao2[9] = 6;

    duizhao3[1] = 1;
    duizhao3[2] = 1;
    duizhao3[3] = 2;
    duizhao3[4] = 3;
    duizhao3[5] = 4;
    duizhao3[6] = 4;
    duizhao3[7] = 5;
    duizhao3[8] = 6;
    duizhao3[9] = 7;

    duizhao4[2] = 1;
    duizhao4[3] = 2;
    duizhao4[4] = 2;
    duizhao4[5] = 3;
    duizhao4[6] = 4;
    duizhao4[7] = 5;
    duizhao4[8] = 5;
    duizhao4[9] = 6;

    int l,r,ans = 0;
    cin>>l>>r;
    int templ = l,tempr = r;
    while(templ%10!=0)
    {
        templ--;
    }
    while(tempr%10!=0)
    {
        tempr++;
    }
    if((tempr/10-templ/10)%2==0)
    {
        ans+=(tempr/10-templ/10)/2*15;
    }
    else
    {
        ans+=(tempr/10-templ/10)/2*15;
        if((tempr/10)%2==0) ans+=8;
        else ans+=7;
    }
    // cout<<ans<<"  "<<tempr<<"  "<<templ<<endl;
    if((templ/10) == 0)
    {
        ans -= duizhao1[l%10] -1;
    }
    else if((templ/10)%2 == 0)
    {
        ans -= duizhao1[l%10];
    }
    else
    {
        ans -= duizhao2[l%10];
    }
    if(r%10 == 0)
    {

    }
    else if((tempr/10)%2 == 1)
    {
        ans -= 7 - duizhao3[r%10];
        if(r%10 == 0)
        {
            ans-=1;
        }
    }
    else
    {
        ans -= 7 - duizhao4[r%10];
    }
    cout<<ans;
    return 0;
}