#include<bits/stdc++.h>
using namespace std;
long long mem[2022];
long long dfs(int num)
{
    if(mem[num]!=-1) return mem[num];
    cout<<num<<endl;
    long long sum  = LONG_LONG_MAX;
    for(int i=0;i<=num-1;i++)
    {
        long long leftval = 2*dfs(i);
        long long rightval = 3*dfs(num-1-i);
        long long numval = i*i*(num-1-i);
        
        sum = min(sum,1+leftval+rightval+numval);
    }
    mem[num] = sum; 
    return sum;
}

int main()
{
    for(int i=0;i<=2021;i++) mem[i] = -1;
    mem[0] = 0;
    mem[1] = 1;
    cout<<dfs(2021);
    return 0;
}