#include<bits/stdc++.h>
using namespace std;
int main(){

    int N = 10000;
    vector<int> primes(N+1);
    vector<int> st(N+1);

    int cnt = 0;
    for(int i=2;i<=N;i++){
        if(st[i] == 0) primes[cnt++] = i;
        for(int j=0;j<cnt;j++)
        {
            if(i*primes[j]>N) break;
            st[primes[j]*i] = 1;
            if(i%primes[j] == 0) break;
        }
    }

    for(int i=0;i<10;i++)
    {
        cout<<primes[i]<<" ";
    }
    return 0;
}