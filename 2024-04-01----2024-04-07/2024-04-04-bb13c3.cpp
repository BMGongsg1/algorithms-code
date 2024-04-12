#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin>>a;
    int index = a[1]-'0';

    function<pair<int,int>(int,pair<int,int>)> dfs = [&](int index,pair<int,int> xy)->pair<int,int>
    {
        if(index == 0)
        {
            return xy;
        }
        int small = xy.first/2;
        int big = xy.second;
        if(small>big) swap(small,big);
        pair<int,int> temp = {big,small};
        return dfs(index-1,temp);
    };

    pair<int,int> ans = dfs(index,{1189,841});
    cout<<ans.first<<endl;
    cout<<ans.second<<endl;
    return 0;
}