//测试用
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int,int>> a(5);
    a[0] ={-1,5};
    a[1] ={-1,4};
    a[2] ={-1,4};
    a[3] ={-1,2};
    a[4] ={-1,1};
    auto it = lower_bound(a.begin(),a.end(),3,[](const pair<int,int>& a1,const int b)
    {
        return a1.second>b;
    });
    if(it<a.end())cout<<it->second<<endl;
    return 0;
}