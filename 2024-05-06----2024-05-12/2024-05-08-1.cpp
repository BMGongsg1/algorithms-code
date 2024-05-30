#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int i=40;i>=1;i--){
        for(int j=1;j<=20;j++)
        {
            int k = j*10;
            if(i*5+k*2+j>200)
            {
                break;
            }
            if(i*5+k*2+j==200)
            {
                cout<<i<<"  "<<j<<"  "<<k<<endl;
                i=0;
            }
        }
    }
    return 0;
}