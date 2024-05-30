#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    map<int,int> mapp;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        mapp[temp]++;
    }

    // int before
    // for(auto [a,b]:mapp)
    // {
    //     if(dp[a])
    // }

    vector<pair<int,int>> nums;
    for(auto [a,b]:mapp){
        nums.push_back({a,b});
    }

    
    vector<int> dp(1e5+100);
    dp[nums[0].first] = nums[0].second;
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    // pq.push_back({nums[0].second,nums[0].first});
    for(int i=1;i<nums.size();i++)
    {
        if()

        // auto temp = pq.front();
        // int now = 0;
        // if(nums[i].first-temp.second == k)
        // {
        //     pq.pop();
        //     now = pq.front().first+nums[i].second;
        //     pq.push(temp);
        //     pq.push({now,nums[i].first});
        // }
        // else{
        //     pq.front().second += nums[i]. 
        // }
    }
    return 0;
}