#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    str = ' '+str;
    vector<int> pre(str.size()+2);
    vector<int> nxt(str.size()+2);
    vector<int> index(26);
    for(int i=1;i<str.size();i++)
    {
        pre[i] = index[str[i]-'a'];
        index[str[i]-'a'] = i;
    }
    for(int i=0;i<26;i++){
        index[i] = str.size();
    }
    for(int i=str.size()-1;i>=1;i--)
    {
        nxt[i] = index[str[i]-'a'];
        index[str[i]-'a'] = i;
    }

    long long ans = 0;
    for(int i=1;i<str.size();i++)
    {
        ans+=(i-pre[i]+1)*(nxt[i]-i);
    }
    cout<<ans;
    return 0;
}