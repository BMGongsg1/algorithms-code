#include<bits/stdc++.h>
using namespace std;
int main()
{
    int summ = 0;
    for(int i=1;i<=2020;i++)
    {
        int temp = i;
        while(temp)
        {
            if(temp%10==2)
            {
                summ++;
            }
            temp/=10;
        }
    }
    cout<<summ;

    return 0;
}