#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int flag[10] = {0},cnt = 0;
bool pd(string str)
{
    fill(flag,flag+10,0);
    for(int i=0;i<str.size();i++)
    {
        if(flag[str[i]-'0'] == 1) return false;
        flag[str[i]-'0']++;
    }
    return true;
}
void dfs(int index,string str)
{
    if(str.size() == 10 &&pd(str)) cnt++;
    if(index == v.size() || str.size() >= 10) return;
    dfs(index + 1,str+v[index]);
    dfs(index + 1,str);
}
int main(){
    long long target = 9876543211;
    for(long long i=0;i*i<target;i++)
    {
        string str;
        stringstream ss;
        ss<<i*i;
        ss>>str;
        if(pd(str)) v.push_back(str);
        ss.clear();
    }
    dfs(0,"");
    cout<<cnt;
    return 0;
}