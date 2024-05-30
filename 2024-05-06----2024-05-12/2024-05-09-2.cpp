#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int i=1;;i++)
    {
        int cnt = 0;
        for(int j=1;j<=i;j++){
            if(i%j == 0)
            {
                cnt++;
            }
        }
        if(cnt == 100)
        {
            cout<<i;
            break;
        }
    }
    return 0;
}