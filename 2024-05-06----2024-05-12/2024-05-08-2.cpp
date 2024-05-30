#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int ans = 0;
    function<void(int,int,int)> dfs = [&](int now_num,int all_need,int index)
    {
        if(now_num > all_need) return;
        if(index >= 30)
        {
            if(now_num == all_need)
            {
                // cout<<"ASDASD  "<<now_num<<endl;
                ans++;
            }
            return;
        }

        // cout<<now_num<<"  "<<all_need<<" "<<index<<endl;
        dfs(now_num+1,all_need,index+2);
        dfs(now_num,all_need,index+1);
    };

    for(int i = 0;i<=20;i++)
    {
        dfs(0,i,0);
    }
    cout<<ans;

    return 0;
}