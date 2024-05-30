#include<bits/stdc++.h>
using namespace std;
int main(){
    int f=97,b=127;
    queue<int> q;
    q.push(0);
    int flag = 1,step = 0;
    map<int,int> mapp;
    while(flag)
    {
        int sz = q.size();
        for(int i=0;i<sz;i++)
        {
            int tp = q.front();
            q.pop();
            cout<<tp<<endl;
            if(tp == 1)flag = 0;
            if(mapp[tp]!=0) continue;
            q.push(tp+f);
            q.push(tp-b);
            mapp[tp]++;
            
        }
        step++;
    }
    cout<<step-1<<endl;
    return 0;
}