#include<bits/stdc++.h>
using namespace std;
int main()
{
    string words;
    cin>>words;
    vector<string> str;
    vector<string> before_str;
    int index = 0,flag = 0;
    string temp;
    while(index<words.size()){
        if(words[index]>='A'&&words[index]<='Z')
        {
            if(temp.size()>0)
            {
                str.push_back(temp);
            }
            temp = "";
            temp+=words[index];
        }
        else
        {
            temp += words[index];
        }
        index++;
    }
    str.push_back(temp);
    before_str = str;

    sort(str.begin(),str.end());

    map<string,int> mapp;

    for(int i=0;i<str.size();i++)
    {
        if(mapp[str[i]]!=0) continue;
        mapp[str[i]] = i;
    }

    index = 0;
    vector<int> nums(str.size());
    for(int i=0;i<str.size();i++){
        nums[i] = mapp[before_str[i]];
    }

    vector<int> dp;
    vector<int> path(nums.size());
    path[0] = 1;
    int indexx = 0;
    dp.push_back(nums[0]);
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]>dp.back())
        {
            dp.push_back(nums[i]);
            path[i] = dp.size();
            continue;
        }
        auto it = lower_bound(dp.begin(),dp.end(),nums[i]);
        dp[it-dp.begin()] = nums[i];
        path[i] = it-dp.begin()+1;
    }
    // vector<int> tempdp;
    // tempdp.push_back(nums[0]);
    // for(int i=1;i<nums.size();i++)
    // {
    //     if(nums[i]>tempdp.back())
    //     {
    //         tempdp.push_back(nums[i]);
    //         if(i == indexx)
    //         {
    //             dpp = tempdp;
    //             // cout<<"QWEQW"<<endl;
    //             break;
    //         }
    //         continue;
    //     }

    //     auto it = lower_bound(tempdp.begin(),tempdp.end(),nums[i]);
    //     tempdp[it-tempdp.begin()] = nums[i];
    // }
    

    vector<int> numm(dp.size());
    string ans;
    int now = dp.size();
    for(int i=nums.size()-1;now>0;i--)
    {
        // cout<<
        if(now == path[i])
        {
            numm[now-1] = i;
            now--;
        }
    }
    for(int i=0;i<numm.size();i++)
    {
        ans+=before_str[numm[i]];
    }
    cout<<ans;

    return 0;
}