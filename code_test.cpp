//测试用
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a;
int qpow(int a,int b)
{
	if(b<=3) return b==2?a*a:a*a*a;
	int ans=1;
	while(b)
	{
		if(b&1) ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
bool checkpow(int a,int k) // a 是否为某个数的 k 次方
{
	int x=pow(a,1.0/k)+1e-5;
	return qpow(x,k)==a;
}
int tot=0,prime[1010]; bool vis[4010];
int cnt; pair<int,int> zys[1010];
bool flag;
void dfs(int now,int nowx,bool op)
{
	if(flag || nowx>4000) return;
	if(now==cnt+1)
	{
		if(!op)
		{
			if(a%(nowx*nowx)==0 && checkpow(a/nowx/nowx,3)) flag=1;
		}
		else
		{
			if(a%(nowx*nowx*nowx)==0 && checkpow(a/nowx/nowx/nowx,2)) flag=1;
		}
		return;
	}
	for(int i=0; i<=zys[now].second/(!op?2:3) && nowx<=4000; ++i) // 因为要求平方/立方之后还能整除，所以指数只能取到一半/三分之一
	{
		dfs(now+1,nowx,op);
		nowx*=zys[now].first;
	}
}
signed main()
{
	for(int i=2; i<=4000; ++i)
	{
		if(!vis[i])
		{
			prime[++tot]=i;
			for(int j=i*i; j<=4000; j+=i) vis[j]=1;
		}
	}
	int t; cin>>t; while(t--)
	{
		cin>>a;
		flag=0;
		for(int k=2; k<=60; ++k)
		{
			if(checkpow(a,k)) { flag=1; break; }
		}
		if(flag) { puts("yes"); continue; }
		int tmp=a; cnt=0;
		for(int i=1; i<=tot; ++i)
		{
			if(tmp%prime[i]==0)
			{
				zys[++cnt]={prime[i],0};
				while(tmp%prime[i]==0) ++zys[cnt].second,tmp/=prime[i];
			}
		}
		dfs(1,1,0);
		// 注释的是暴力判断
		// for(int i=2; i<=4000 && i*i<=a; ++i)
		// {
			// if(a%(i*i)==0 && checkpow(a/i/i,3)) { flag=1; break; }
		// }
		if(flag) { puts("ye1s"); continue; }
		dfs(1,1,1);
		// for(int i=2; i<=4000 && i*i*i<=a; ++i)
		// {
			// if(a%(i*i*i)==0 && checkpow(a/i/i/i,2)) { flag=1; break; }
		// }
		puts(flag?"yes":"no");
	}
	return 0;
}