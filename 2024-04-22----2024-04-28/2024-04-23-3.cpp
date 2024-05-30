#include<bits/stdc++.h>
using namespace std;
int main(){
    int maxx = 0;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    for(int i=0;i<n;i++){
        int minn = nums[i];
        for(int j=i;j<n;j++){
            minn = min(minn,nums[j]);
            maxx = max(minn*(j-i+1),maxx);
        }
    }

    cout<<maxx;

    return 0;
}