#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> nums(n,vector<int>(3));
    for(int i=0;i<n;i++) cin>>nums[i][0]>>nums[i][1]>>nums[i][2];

    for(int i=0;i<n;i++) sort(nums[i].begin(),nums[i].end());
    for(int i=0;i<n;i++)
    {
        int cnt = 0;
        for(int j=0;j<3;j++){
            cnt += nums[i][j];
        }
        if(cnt%2 == 0)
        {
            if(nums[i][0]+nums[i][1]>nums[i][2]) cout<<cnt/2<<endl;
            else cout<<(nums[i][0]+nums[i][1])<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }


    }

    return 0;
}