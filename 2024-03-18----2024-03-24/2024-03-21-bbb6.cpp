//2083: [蓝桥杯2023初赛] 子串简写
#include<bits/stdc++.h>
using namespace std;
int main()
{

    int k;
    cin>>k;
    string str1;
    char c1,c2;
    cin>>str1>>c1>>c2;

    int left = 0,right = 0;
    int un_c = 0,able_c = 0;
    long long ans = 0;
    while(right<str1.size())
    {
        while(right-left<k-1)
        {
            if(str1[right++] == c2)
            {
                // cout<<"ASDDSA  "<<able_c<<endl;
                ans += able_c;
            }
        }
        if(str1[left++]==c1) able_c++;
    }
    cout<<ans<<endl;
    return 0;
}