//2097: [蓝桥杯2023初赛] 与或异或
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    vector<int> temp = {1,0,1,0,1};
    function<int(vector<int>,int)> dfs = [&](vector<int> temp,int index)->int{
        if(index == 0&&temp[0] == 1)return 1;
        else if(index ==0 && temp[0] != 1) return 0;  

        long long ans = 0;
        if(index == 4)
        {
            vector<int> ttemp(index);
            for(int i=0;i<3;i++)
            {
                if(i==0)
                {
                    ttemp[0] = temp[0]|temp[1];
                }
                else if(i==1)
                {
                    ttemp[0] = temp[0]&temp[1];
                }
                else{
                    ttemp[0] = temp[0]^temp[1];
                }
                for(int j=0;j<3;j++)
                {
                    if(j==0)
                    {
                        ttemp[1] = temp[1]|temp[2];
                    }
                    else if(j==1)
                    {
                        ttemp[1] = temp[1]&temp[2];
                    }
                    else{
                        ttemp[1] = temp[1]^temp[2];
                    }
                    for(int k=0;k<3;k++)
                    {
                        if(k==0)
                        {
                            ttemp[2] = temp[3]|temp[2];
                        }
                        else if(k==1)
                        {
                            ttemp[2] = temp[2]&temp[3];
                        }
                        else{
                            ttemp[2] = temp[2]^temp[3];
                        }
                        for(int l=0;l<3;l++)
                        {
                            if(l==0)
                            {
                                ttemp[3] = temp[3]|temp[4];
                            }
                            else if(l==1)
                            {
                                ttemp[3] = temp[3]&temp[4];
                            }
                            else{
                                ttemp[3] = temp[3]^temp[4];
                            }
                            ans+=dfs(ttemp,index-1);
                        }
                    }
                }
            }
        }

        if(index == 3)
        {
            vector<int> ttemp(index);
            for(int i=0;i<3;i++)
            {
                if(i==0)
                {
                    ttemp[0] = temp[0]|temp[1];
                }
                else if(i==1)
                {
                    ttemp[0] = temp[0]&temp[1];
                }
                else{
                    ttemp[0] = temp[0]^temp[1];
                }
                for(int j=0;j<3;j++)
                {
                    if(j==0)
                    {
                        ttemp[1] = temp[1]|temp[2];
                    }
                    else if(j==1)
                    {
                        ttemp[1] = temp[1]&temp[2];
                    }
                    else{
                        ttemp[1] = temp[1]^temp[2];
                    }
                    for(int k=0;k<3;k++)
                    {
                        if(k==0)
                        {
                            ttemp[2] = temp[3]|temp[2];
                        }
                        else if(k==1)
                        {
                            ttemp[2] = temp[2]&temp[3];
                        }
                        else{
                            ttemp[2] = temp[2]^temp[3];
                        }
                        ans+=dfs(ttemp,index-1);
                    }
                }
            }
        }

        if(index == 2){
            vector<int> ttemp(index);
            for(int i=0;i<3;i++)
            {
                if(i==0)
                {
                    ttemp[0] = temp[0]|temp[1];
                }
                else if(i==1)
                {
                    ttemp[0] = temp[0]&temp[1];
                }
                else{
                    ttemp[0] = temp[0]^temp[1];
                }
                for(int j=0;j<3;j++)
                {
                    if(j==0)
                    {
                        ttemp[1] = temp[1]|temp[2];
                    }
                    else if(j==1)
                    {
                        ttemp[1] = temp[1]&temp[2];
                    }
                    else{
                        ttemp[1] = temp[1]^temp[2];
                    }
                    ans+=dfs(ttemp,index-1);
                }
            }
        }

        if(index == 1){
            vector<int> ttemp(index);
            for(int i=0;i<3;i++)
            {
                if(i==0)
                {
                    ttemp[0] = temp[0]|temp[1];
                }
                else if(i==1)
                {
                    ttemp[0] = temp[0]&temp[1];
                }
                else{
                    ttemp[0] = temp[0]^temp[1];
                }
                ans+=dfs(ttemp,index-1);
            }
        }
        return ans;
    };

    cout<<dfs(temp,4);

    return 0;
}