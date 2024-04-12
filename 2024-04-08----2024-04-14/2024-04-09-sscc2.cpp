#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str1,str2;
    cin>>str1;

    int flag = 0;
    for(int i=0;i<str1.size();i++)
    {
        
        if(str1[i] == 'Q')
        {
            flag = 0;
            str2 += 'Q';
        }
        else if(str1[i] == 'L'&&flag == 0)
        {
            flag = 1;
            str2 += 'L';
        }
    }

    cout<<str2<<endl;

    return 0;
}