#include<bits/stdc++.h>
using namespace std;
bool pd(int a,int b)
{
    if(a == 0&&b==1) return false;
    if(a==1&&b==2) return false;
    if(a==2&&b==3) return false;
    return true;
}
int main(){
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            if(pd(i,j))
            {
                cout<<char('A'+i)<<" "<<char('A'+j)<<endl;
            }
        }
    }

    return 0;
}