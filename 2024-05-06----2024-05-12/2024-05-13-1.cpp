#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_set<int> sett;
    for(long long i=100;i<10000000;i++)
    {
        long long temp = i*i;
        int one = temp%10;
        temp/=10;
        int ten = temp%10;
        int num = ten*10+one;
        if(sett.find(num)==sett.end()){
            cout<<num<<endl;
            sett.insert(num);
        }
    }
    cout<<sett.size();
    return 0;
}