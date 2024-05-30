#include<bits/stdc++.h>
using namespace std;
long long mem[66];
long long sum;
long long N;
long long K;
void dfs(long long index,long long knum,long long number)
{
    
    if(knum == 0&&number<=N) 
    {
        // cout<<index<<" "<<knum<<" a "<<number<<endl;
        sum++;
        return;
    }
    // cout<<index<<" "<<knum<<" "<<number<<endl;
    // 
    for(long long i=index-1;i>=0;i--)
    {
        // cout<<number+(1LL<<i)<<endl;
        if(i<(knum-1)||(number+(1LL<<i))>N) continue;
        // cout<<"inde"<<endl;
        dfs(i,knum-1,number+(1LL<<i));
    }
}
int main(){
    cin>>N>>K;
    for(long long i=62;i>=0;i--)
    {
        dfs(i,K-1,(1ULL<<i));
    }
    cout<<sum;
    return 0;
}