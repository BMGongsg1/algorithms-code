#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b;
    cin>>a>>b;
    int maxx = -1;
    int maxi = 0;
    for(int i=a;i<=b;i++)
    {
        int temp = i;
        int ans = 0;
        while(temp)
        {
            int z = temp%10;
            if(z == 0||z==6||z==9)
            {
                ans++;
            }
            else if(z == 8) ans+=2;
            temp/=10;
        }
        if(maxx<ans){
            maxx = max(maxx,ans);
            maxi = i;
        }
    }
    cout<<maxi<<endl;
    return 0;
}