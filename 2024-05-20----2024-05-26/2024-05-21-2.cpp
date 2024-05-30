#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int z=0;z<t;z++){
        int n;
        // cout<<"n"<<endl;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        // cout<<"numsend"<<endl;
        vector<vector<int>> pre(n,vector<int>(n+1));
        for(int i=0;i<n;i++){
            pre[i][i] = nums[i];
            for(int j=i+1;j<n;j++)
            {
                pre[i][j] = pre[i][j-1]|nums[j];
            }
        }
        for(int k=1;k<=n;k++)
        {
            // cout<<"inside"<<k<<endl;
            int flag = 1;
            for(int i=0;i<=n-k;i++)
            {
                for(int j=0;j<=n-k;j++)
                {
                    if(i == j)continue;
                    if(pre[i][i+k-1] != pre[j][j+k-1])
                    {
                        // cout<<i<<" "<<j<<" "<<pre[i][i+k-1]<<" "<<pre[j][j+k-1]<<endl;
                        flag = 0;
                        break;
                    }
                }
                if(flag == 0) break;
            }     
            if(flag)
            {
                cout<<k<<endl;
                break;                
            }
        }
    }
    return 0;
}