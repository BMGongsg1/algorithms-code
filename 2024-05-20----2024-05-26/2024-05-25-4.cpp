#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    int maxx = 0;
    for(int i=1;i<n;i++) 
    {
        maxx = max(maxx,abs(nums[i]-nums[i-1]));
    }
    cout<<maxx;
    return 0;
}