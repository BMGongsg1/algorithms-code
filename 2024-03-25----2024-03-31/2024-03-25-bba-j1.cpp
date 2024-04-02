//2093: [蓝桥杯2023初赛] 互质数的个数(无欧拉函数版本，超时)
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b;
    long long MOD = 998244353;
    cin>>a>>b;
    long long should_D = 1;
    for(long long i=2;i<a;i++)
    {
        if(__gcd(i,a)!=1)
        {
            should_D++;
        }
    }
    // cout<<should_D<<endl;
    auto qpow = [&](long long a1,long long b1)->long long{
        long long ans = 1;
        while(b1){
            if(b1&1) ans*=a1;
            ans %= MOD;
            a1 *= a1;
            a1 %= MOD;
            b1 >>= 1;
        }
        return ans%MOD;
    };

    // auto dd = [&](unsigned long long a1,unsigned long long b1,unsigned long long d)->unsigned long long{
    //     unsigned long long ans = 0;
    //     while(b1){
    //         if(b1&1) 
    //     }
    // }

    long long sum = qpow(a,b);
    long long ddd = (should_D*qpow(a,b-1))%MOD;
    cout<<(sum+MOD-ddd)%MOD<<endl;


    return 0;
}