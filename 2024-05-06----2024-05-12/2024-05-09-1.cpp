#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> su;
    for(int i=2;i<=2019;i++){
        int flag = 1;
        for(int j=i-1;j>1;j--)
        {
            if(i%j == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag) su.push_back(i);
    }
    for(int i=0;i<su.size();i++) cout<<su[i]<<" ";

    vector<long long> dp(2020);
    dp[0] = 1;
    for(int i=0;i<su.size();i++){
        for(int j=2019;j>=su[i];j--){
            dp[j] += dp[j-su[i]];
            // cout<<dp[j]<<endl;
        }
    }
    cout<<dp[2019];

    return 0;
}