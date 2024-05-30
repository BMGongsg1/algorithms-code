#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int i=20;i<1000;i++){
        for(int j=20;j<1000;j++)
        {
            if((i-20) == (j-20)*2)
            {
                if(j*1.5 == i)
                {
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}