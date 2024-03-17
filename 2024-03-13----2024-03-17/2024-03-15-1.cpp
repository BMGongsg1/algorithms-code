//P1140 相似基因
#include<bits/stdc++.h>
using namespace std;
struct pair_hash
{
    size_t operator() (const pair<char,char>& pair) const{
        return hash<char>()(pair.first) ^ hash<char>()(pair.second);
    }
};

int main()
{
    int n,m;
    string str1,str2;
    cin>>n>>str1;
    cin>>m>>str2;
    str1 = ' '+str1;
    str2 = ' '+str2;
    unordered_map<pair<char,char>,int,pair_hash> mapp;
    mapp[{'A', 'A'}] = 5;
    mapp[{'A', 'C'}] = -1;
    mapp[{'A', 'G'}] = -2;
    mapp[{'A', 'T'}] = -1;
    mapp[{'A', '-'}] = -3;

    mapp[{'C', 'A'}] = -1;
    mapp[{'C', 'C'}] = 5;
    mapp[{'C', 'G'}] = -3;
    mapp[{'C', 'T'}] = -2;
    mapp[{'C', '-'}] = -4;

    mapp[{'G', 'A'}] = -2;
    mapp[{'G', 'C'}] = -3;
    mapp[{'G', 'G'}] = 5;
    mapp[{'G', 'T'}] = -2;
    mapp[{'G', '-'}] = -2;

    mapp[{'T', 'A'}] = -1;
    mapp[{'T', 'C'}] = -2;
    mapp[{'T', 'G'}] = -2;
    mapp[{'T', 'T'}] = 5;
    mapp[{'T', '-'}] = -1;

    mapp[{'-', 'A'}] = -3;
    mapp[{'-', 'C'}] = -4;
    mapp[{'-', 'G'}] = -2;
    mapp[{'-', 'T'}] = -1;
    
    vector<vector<long long>> dp(n+1,vector<long long>(m+1,INT_MIN));
    dp[0][0] = 0;
    for(int i=1;i<=n;i++)
    {
        dp[i][0] = dp[i-1][0] + mapp[{str1[i],'-'}];
    }
    for(int j=1;j<=m;j++)
    {
        dp[0][j] = dp[0][j-1] + mapp[{'-',str2[j]}];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j] = max(dp[i][j],max(dp[i-1][j]+mapp[{str1[i],'-'}],max(dp[i-1][j-1]+mapp[{str1[i],str2[j]}],dp[i][j-1]+mapp[{'-',str2[j]}])));
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}