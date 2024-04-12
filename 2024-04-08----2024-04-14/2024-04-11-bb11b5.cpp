#include<bits/stdc++.h>
using namespace std;
int main(){
    int month[13] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};
    long long day = 5;
    long long ans = 0;
    for(int i=2000;i<=2020;i++)
    {
        cout<<i<<endl;
        for(int j=1;j<=12;j++)
        {
            int days;
            if(j>=10&&i==2020) continue;
            if(i%4==0&&j==2) days = 29;
            else days = month[j];
            for(int k=1;k<=days;k++)
            {
                // cout<<j<<"  "<<k<<"  "<<((i%4==0&&j==2)?29:month[j])<<endl;
                if(day%7==0||k==1)
                {
                    ans++;
                }
                day++;
                ans++;
            }
        }
    }
    cout<<ans+2;
    return 0;
}