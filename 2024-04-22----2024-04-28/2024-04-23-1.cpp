#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<int,int> mapp;
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        mapp[temp]++;
    }

    int minn = 0,mini = -1;
    for(auto it = mapp.begin();it!=mapp.end();it++)
    {
        int a = it->first;
        int b = it->second;
        if(b>minn||(b==minn&&a<mini))
        {
            minn = b;
            mini = a;
        }
    }

    cout<<mini;
    return 0;
}