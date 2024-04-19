#include<bits/stdc++.h>
using namespace std;
int main(){

    int N = 1e5;
    int n;
    vector<int> primes(N);
    vector<int> st(N);

    for(int i=2;i<=n/i;i++){
        if(st[i] ==0)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                st[j] = 1;
            }
        }
    }

    return 0;
}