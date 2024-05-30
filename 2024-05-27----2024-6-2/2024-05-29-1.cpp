#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int N = 100000000;
    vector<long long> primes(N+1);
    vector<long long> st(N+1);

    long long cnt = 0;
    for(long long i=2;i<=N;i++)
    {
        if(st[i] == 0)primes[cnt++] = i;
        for(long long j=0;j<cnt;j++)
        {
            if(i*primes[j]>N) break;
            st[primes[j]*i] = 1;
            if(i%primes[j] == 0)break;
        }
    }
    for(int i=0;i<100;i++) cout<<primes[i]<<endl;
    cout<<"ASDAS"<<endl;
    long long ans = 0;
    for(long long i=0;i<primes.size();i++)
    {
        int flag = 0;
        for(long long j=i+1;j<primes.size();j++)
        {
            double temp = primes[i] * primes[j];
            // cout<<primes[i]<<" "<<primes[j]<<endl;
            if(temp*temp>=2333)
            {
                if(temp*temp>23333333333333) {break;}
                ans++;
            }
        }
        if(primes[i]*primes[i]>23333333333333) break;
    }



    
    // for(long long i=20;i<100000000000;i++)
    // {
    //     for(int j=)
    // }
    cout<<ans;
    return 0;
}