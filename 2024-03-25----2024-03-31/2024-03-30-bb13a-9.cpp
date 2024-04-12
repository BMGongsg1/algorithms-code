//数的拆分
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a;
int qpow(int a,int b)
{
    if(b<=3) return b==2?a*a:a*a*a;
    int ans = 1;
    while(b)
    {
        if(b&1) ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}
bool check(int a,int k)
{
    int x = pow(a,1.0/k)+1e-5;
    return qpow(x,k) == a;
}
int flag,cnt;
int tot = 0,prime[1010];bool vis[4010];
pair<int,int> z[1010];
void dfs(int now,int nowx,bool op)
{
    if(flag||nowx>4000) return;
    if(now == cnt+1)
    {
        if(!op)
        {
            if(a%(nowx*nowx)==0 && check(a/nowx/nowx,3)) flag = 1;
        }
        else{
            if(a%(nowx*nowx*nowx)==0 && check(a/nowx/nowx/nowx,2)) flag = 1;
        }
        return;
    }
    for(int i=0;i<=z[now].second/(!op?2:3)&&nowx<=4000;i++)
    {
        dfs(now+1,nowx,op);
        nowx*=z[now].first;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    for(int i=2;i<=4000;i++)
    {
        if(!vis[i]){
            prime[++tot] = i;
            for(int j = i*i;j<=4000;j+=i) vis[j] = 1;
        }
    }
    int t;cin>>t;
    while(t--)
    {
        cin>>a;
        flag = 0;
        for(int k=2;k<=60;k++)
        {
            if(check(a,k))
            {
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            cout<<"yes"<<endl;
            continue;
        }
        int temp = a;cnt = 0;
        for(int i=1;i<=tot;i++)
        {
            if(temp%prime[i]==0)
            {
                z[++cnt] = {prime[i],0};
                while(temp%prime[i] == 0)
                {
                    ++z[cnt].second;
                    temp/=prime[i];
                }
            }
        }
        dfs(1,1,0);
        if(flag)
        {
            cout<<"yes"<<endl;
            continue;
        }
        dfs(1,1,1);
        cout<<(flag?"yes":"no")<<endl;
    }

    return 0;
}