#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int tempa,tempb;
        cin>>tempa>>tempb;
        if(tempa<=tempb*2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}