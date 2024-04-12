#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<nums.size();i++)
    {
        cin>>nums[i];
    }

    int left = 0,right = nums.size()-1;
    while(left<right)
    {
        if(nums[left] > nums[right])
        {
            swap(nums[left],nums[right]);
        }
        left++,right--;
    }
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]<nums[i-1])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}