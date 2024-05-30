#include<bits/stdc++.h>
using namespace std;
int main(){
    int N = 10000;
    vector<int> primes(N+1);
    vector<int> st(N+1);
    int cnt = 0;
    for(int i=2;i<N;i++){
        if(st[i] == 0) primes[cnt++] = i;
        for(int j = 0;j<cnt;j++)
        {
            if(primes[j]*i>N) break;
            st[primes[j]*i] = 1;
            if(i%primes[j] == 0) break;
        }
    }

    unordered_map<int,int> mapp;
    for(int i=0;i<cnt;i++)
    {
        mapp[primes[i]]++;
    }

    int maxx = 0;
    for(int i=10000;i>=1;i-=2)
    {
        for(int j=0;j<i/2;j++)
        {
            int temp = i-j;
            if(mapp.find(j) != mapp.end()&&mapp.find(temp) != mapp.end())
            {
                maxx = max(j,maxx);
                break;
            }
        }
    }
    cout<<maxx;
    return 0;
}