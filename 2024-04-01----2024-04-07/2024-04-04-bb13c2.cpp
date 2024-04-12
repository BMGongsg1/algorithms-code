#include<bits/stdc++.h>
using namespace std;
int main()
{
    int day[13] ={0,31,28,31,30,31,30,31,31,30,31,30,31};
    auto pd = [&](int num)->pair<int,int>{
        int weishu = 0;
        int flag = 1;
        pair<int,int> fir = {-1,-1};
        pair<int,int> sec = {0,0};
        while(num)
        {
            if(fir.first == -1)
            {
                fir.first = num%10;
                fir.second = 1;
            }
            else if(fir.first!=num%10&&sec.first == 0)
            {
                sec.first = num%10;
                sec.second = 1;
            }
            else if(fir.first == num%10)
            {
                fir.second++;
            }
            else if(sec.first == num%10)
            {
                sec.second++;
            }
            num/=10;
            weishu++;
        }
        if(fir.first == 0)
        {
            fir.second += 4-weishu;
        }
        else if(sec.first == 0)
        {
            sec.second += 4-weishu;
        }

        if(fir.second == 1&&sec.second == 3)
        {
            return {fir.first,sec.first};
        }
        else if(fir.second == 3&&sec.second == 1)
        {
            return {sec.first,fir.first};
        }
        return {-1,-1};
    };
    long long ans = 0;
    for(int i=0;i<=9999;i++)
    {
        // cout<<i<<endl;
        pair<int,int> year = pd(i);
        if(year.first == -1) continue;
        if(i==2202)
        {
            cout<<endl<<endl<<endl;
            cout<<year.first<<"  "<<year.second<<endl;
            cout<<endl<<endl<<endl;
        }
        for(int m=1;m<=12;m++)
        {
            // cout<<m<<endl;
            int flag = 0;
            if((i%4==0&&i%100!=0)||(i%400==0))
            {
                flag = 1;
            }
            for(int d=1;d<=(flag==0?day[m]:29);d++)
            {
                // cout<<d<<endl;
                int month_day = m*100+d;
                
                pair<int,int> monday = pd(month_day);
                if(i==2202&&month_day==222){
                    cout<<endl<<endl<<endl;
                    cout<<monday.first<<"  "<<monday.second<<endl;
                    cout<<endl<<endl<<endl;
                }
                if(monday.first==-1||monday!=year)
                {
                    continue;
                }
                for(int h=1;h<=24;h++)
                {
                    for(int mn=1;mn<=60;mn++)
                    {
                        
                        int hour_min = h*100+mn;
                        pair<int,int> homin = pd(hour_min);

                        if(year == monday&&monday == homin){
                            cout<<i<<"  "<<m<<"  "<<d<<" "<<h<<"  "<<mn<<endl;
                            ans++;
                        }

                    }
                }
            }
        }
    } 

    cout<<ans;
    // pair<int,int> temp = pd(1111);
    // cout<<temp.first<<endl;
    return 0;
}