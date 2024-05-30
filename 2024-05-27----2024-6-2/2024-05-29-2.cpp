#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    vector<int> nums(n+1);
    for(int i=0;i<n;i++){
        nums[a[i]]++;
    } 

    int yichu = 0,one = 0;
    for(int i=1;i<=n;i++)
    {
        if(nums[i]>2) yichu += nums[i] - 2;
        if(nums[i]==1) one ++;
    }

    int ans = 0;
    
    if(yichu>=one){
        ans += one;
        yichu -= one;
        ans += yichu/2;
    }
    else
    {
        one -= yichu;
        ans += yichu;
        ans += one/2;
    }

    cout<<ans;



    return 0;
}