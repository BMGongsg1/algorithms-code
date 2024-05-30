#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> nums(n,vector<int>(2));
    for(int i=0;i<n;i++)
    {
        // cin>>nums[i][0]>>nums[i][1]>>nums[i][2];
        int a,b,c;
        cin>>a>>b>>c;
        nums[i][0] = a+b;
        nums[i][1] = c;
    }

    
    
    return 0;
}