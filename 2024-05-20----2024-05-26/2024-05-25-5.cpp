#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> mapp(21);
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        for(int j=0;j<20;j++){
            if(5-mapp[j]>=num)
            {
                int temp = mapp[j];
                mapp[j] += num;
                for(int k=temp+1;k<=mapp[j];k++) cout<<j*5+k<<" ";
                cout<<endl;
                break;
            }
        }
    }
    return 0;
}