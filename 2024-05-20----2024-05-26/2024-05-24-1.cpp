#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 20210606;
    vector<int> primes(n+1);
    vector<int> st(n+1);
    unordered_map<int,int> mapp;
    mapp[2]++;
    mapp[3]++;
    mapp[5]++;
    mapp[7]++;
    int cnt = 0;
    for(int i=2;i<=n;i++)
    {
        if(st[i] == 0) primes[cnt++] = i;
        for(int j=0;j<cnt;j++)
        {
            if(i*primes[j]>n) break;
            st[primes[j]*i] = 1;
            if(i%primes[j] == 0) break;
        }
    }

    int sum = 0;
    for(int i=0;i<cnt;i++)
    {
        int temp = primes[i],flag = 1;
        while(temp)
        {
            if(mapp[temp%10] == 0)
            {
                flag = 0;
                break;
            }
            temp/=10;
        }
        if(flag) sum++;
    }
    cout<<sum<<endl;

    return 0;
}