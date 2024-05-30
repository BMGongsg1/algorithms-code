#include<bits/stdc++.h>
using namespace std;
int main(){
    int minn = INT_MAX;
    for(int i=2020;i<=10000;i++){
        for(int j=i+1;j<=10000;j++)
        {
            if(j*j-i*i ==i*i - 2019*2019)
            {
                minn = min(i+j,minn);
            }
        }
    }
    cout<<minn;
    return 0;
}