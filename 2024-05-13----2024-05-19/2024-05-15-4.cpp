#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums(10);
    // vector<int> pd(10);
    long long maxx = 0;
    function<void(int,int,int,int)> dfs = [&](int a,int b,int cnt,int flagg){

        if(cnt == 9&&flagg)
        {
            long long temp = (long long)a*b;
            long long ttemp = (long long)a*b;
            int flag = 1;
            vector<int> pd(10);
            while(temp)
            {
                pd[temp%10]++;
                if(pd[temp%10]>=2)
                {
                    flag = 0;
                    break;
                }
                temp/=10;
            }
            if(pd[0]>0) flag = 0;
            if(flag)
            {
                maxx = max(maxx,ttemp);
            }
            // if(a == 9)cout<<a<<" "<<b<<" "<<temp<<" "<<flag<<endl;
            return;
        }      
        
        for(int i=1;i<=9;i++)
        {
            if(!nums[i])
            {
                nums[i]  = 1;
                if(flagg)
                {
                    dfs(a,b*10+i,cnt+1,flagg);
                }
                else{
                    dfs(a*10+i,b,cnt+1,flagg);
                    dfs(a,b*10+i,cnt+1,1);
                }
                nums[i] = 0;

            }
        }

    };

    dfs(0,0,0,0);

    cout<<maxx;

    return 0;
}