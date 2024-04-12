#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    long long lk = 0,rk = 0,lflag = 0,rflag = 0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i] == '(') {lk++;lflag = i}
        if(str[i]==')')
        {
            if(lk>0)
            {
                lk--;
            }
            else
            {
                rk++;
                rflag = i;
            }
        }
    }
    long long left = 0,right = 0;
    long long ans = 0;
    while(rk)
    {
        while(nums[right] == '(') right++;
        long long cnt = 0;
        while(nums[right]==')')
        {
            cnt++;
            right++;
        }
        ans += 
    }
    return 0;
}