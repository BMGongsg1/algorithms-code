#include<bits/stdc++.h>
using namespace std;
int main()
{
    int mo[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int cnt = 0;
    for(int y=2001;y<=2021;y++)
    {
        for(int m=1;m<=12;m++)
        {
            int limit;
            if(y%4 == 0 && m == 2)
            {
                limit = 29;
            }
            else limit = mo[m];

            for(int d=1;d<=limit;d++)
            {
                int tempy = y,tempm = m,tempd = d;
                int sum = 0;
                while(tempy)
                {
                    sum+=tempy%10;
                    tempy/=10;
                }
                while(tempm)
                {
                    sum+=tempm%10;
                    tempm/=10;
                }
                while(tempd)
                {
                    sum+=tempd%10;
                    tempd/=10;
                }
                int tempsum = sqrt(sum+0.01);
                if(tempsum*tempsum == sum) cnt++;
            }
        }
    }
    cout<<cnt;

    return 0;
}