#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int summ = 0;
    int temp = 1;
    for(int i=0;i<str.size()-1;i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            summ+= (str[i]-'0')*temp;
            temp++;
        }

    }

    summ%=11;
    if((summ == 10&&str[str.size()-1]=='X')||str[str.size()-1] == summ+'0') cout<<"Right";
    else{
        if(summ<=9)str[str.size()-1] = summ+'0';
        else str[str.size()-1] = 'X';
        cout<<str;
    }
    return 0;
}