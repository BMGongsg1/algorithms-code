#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    if(n==1) {cout<<1<<endl;return 0;}

    vector<long long> a(50000);
    vector<long long> b(50000);
    a[0] = 1;
    b[0] = 1;
    for(long long i=3;i<=44723;i++)
    {
        int m = i/2;
        for(long long j=1;j<=m;j++)
        {
            if(j==m&&i%2 == 1)
            {
                b[j] = a[j-1]*2;
            }
            else{
                b[j] = a[j-1]+a[j];
            }
            a[j-1] = b[j-1];
            if(b[j] == n)
            {
                cout<<i*(i-1)/2+j+1;
                return 0;
            }
        }
        a[m] = b[m];
    }

    cout<<n*(n+1)/2+2;
    // long long num = n*(n+1)/2+2; 
    // for(int i=2;i<=n;i++)
    // {
    //     if(n%i==0)
    //     {
    //         long long temp = n/i;  
    //         long long tempi = i-1;
    //         long long cnt = 2;
    //         int flag = 0;
    //         while(tempi>cnt)
    //         {
    //             temp*=cnt++;
    //             if(temp%tempi==0)
    //             {
    //                 flag = 1;
    //             }
    //             temp/=tempi--;
    //         }
    //         if(flag)
    //         {
    //             cout<<i<<endl;
    //             num = i*(i-1)/2+cnt;
    //             break;
    //         }
    //     }
    // }
    return 0;
}