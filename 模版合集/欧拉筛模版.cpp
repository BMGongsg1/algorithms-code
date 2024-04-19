#include<bits/stdc++.h>
using namespace std;
int main(){

    int N = 10000;
    vector<int> primes(N);
    vector<int> st(N);

    int cnt = 0;
    for(int i=2;i<=N;i++){
        if(st[i] == 0) primes[cnt++] = i;
        for(int j=0;primes[j]<=N/i;j++)
        {
            st[primes[j]*i] = 1;
            if(i% primes[j] == 0) break;
        }
    }

    for(int i=0;i<100;i++)
    {
        cout<<primes[i]<<" ";
    }
    return 0;
}