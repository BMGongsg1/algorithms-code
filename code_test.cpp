//测试用
#include<bits/stdc++.h>
using namespace std;

long long pow(int a,int n,int m)
{
	long long ans = 1;
	while(n)
	{
		if(n&1) ans = (ans*a)%m;
		a = (a*a)%m;
		n>>=1;
	}

	return ans;
}

int main(){

	cout<<pow(2,13,10909090)<<endl;
	return 0;
}