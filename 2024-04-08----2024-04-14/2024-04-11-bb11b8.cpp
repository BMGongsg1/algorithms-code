#include<bits/stdc++.h>
using namespace std;
int main(){
    int month[13] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};
    int beginn,endd;
    cin>>beginn;
    cin>>endd;

    int begin_day = beginn%100,endd_day = endd%100;
    beginn/=100,endd/=100;

    int begin_month = beginn%100,endd_month = endd%100;
    beginn/=100,endd/=100;

    // cout<<beginn<<<begin_month<<begin_day<<"  "<<endd<<endd_month<<endd_day<<endl;

    long long ans = 0;
    vector<int> year(4);
    vector<int> date(4);
    for(int i=beginn;i<=endd;i++)
    {
        int temp = i;
        int cnt = 3;
        while(temp)
        {
            year[cnt--] = temp%10;
            temp/=10;
        }
        for(int j=1;j<=12;j++)
        {
            int days;
            if((j<begin_month&&i==beginn)||(j>endd_month&&i==endd)) continue;
            if(((i%400==0)||(i%4==0&&i%100!=0))&&j==2) days = 29;
            else days = month[j];
            for(int k=1;k<=days;k++)
            {
                // cout<<j<<"  "<<k<<"  "<<((i%4==0&&j==2)?29:month[j])<<endl;
                if((j==begin_month&&i==beginn&&i<begin_day)||(j==endd_month&&i==endd&&k>endd_day)) continue;
                int tempp = j*100+k;
                int cntt = 0;
                while(tempp)
                {
                    date[cntt++] = tempp%10;
                    tempp/=10;
                }  
                if(cntt==3)
                {
                    date[cntt] = 0;
                }

                int flag = 0;
                for(int g=0;g<4;g++)
                {
                    if(year[g]!=date[g])
                    {
                        flag = 1;
                    }
                }
                if(!flag)
                {
                    ans++;
                    // cout<<i<<"  "<<j<<"  "<<k<<endl;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}