#include<bits/stdc++.h>
using namespace std;
int main(){
    int cnt = 0;
    for(int i=1;i<=2020;i++)
    {
        int temp = i,flag = 0;
        while(temp)
        {
            if(temp%10 == 2) flag = 1;
            temp/=10;
        }

        if(flag) cnt++;
    }

    cout<<cnt;

    return 0;
}