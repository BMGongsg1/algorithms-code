#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans = 0;
    ans += 'm'-'a'+10;
    ans*=36;
    ans += 10;
    ans*=36;
    ans += 'n'-'a'+10;
    ans*=36;
    ans += 'y'-'a'+10;
    cout<<ans;
    return 0;
}