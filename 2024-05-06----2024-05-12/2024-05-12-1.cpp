#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans = 0;
    for(int i=2;i<10;i++){
        for(int j=1;j<i;j++)
        {
            for(int k=0;k<j;k++)
            {
               ans++; 
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}