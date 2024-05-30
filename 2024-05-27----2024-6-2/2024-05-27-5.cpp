#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    for(int i=1;i<=2023;i++){
        string temp;
        int ttemp = i;
        while(ttemp)
        {
            temp += char('0'+ttemp%10);
            ttemp/=10;
        }
        reverse(temp.begin(),temp.end());
        str += temp;
    }
    cout<<str<<endl;

    cout<<str.size()<<endl;
    long long ans = 0;
    for(int i=0;i<str.size();i++)
    {
        cout<<i<<endl;
        if(str[i]!='2')continue;
        for(int j=i+1;j<str.size();j++)
        {
            if(str[j]!='0') continue;
            for(int k=j+1;k<str.size();k++)
            {
                if(str[k]!='2') continue;
                for(int l=k+1;l<str.size();l++)
                {
                    if(str[l] == '3') ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}