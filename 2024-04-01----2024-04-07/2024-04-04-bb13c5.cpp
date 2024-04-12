#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    long long n;
    cin>>n;
    vector<pair<int,int>> nums(n);
    for(int i=0;i<n;i++)
    {
        int shuwei = 0;
        int temp = i+1;
        while(temp)
        {
            shuwei+=temp%10;
            temp/=10;
        }
        nums[i] = {shuwei,i+1};
    }
    sort(nums.begin(),nums.end());
    long long m;
    cin>>m;
    cout<<nums[m-1].second;

    return 0;
}