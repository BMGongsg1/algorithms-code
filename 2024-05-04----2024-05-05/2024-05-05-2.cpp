#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        bool flag = 1;
        vector<vector<int>> mapp(n,vector<int>(26));
        for(int j = 0;j<n;j++)
        {
            string temp;
            cin>>temp;
            for(int k=0;k<temp.size();k++){
                mapp[j][temp[k]-'a']++;
            }
        }
        for(int j=0;j<=n/2;j++){
            int fflag = 0;
            for(int k = 0;k<26;k++)
            {
                if(mapp[n-1-j][k]&&mapp[j][k]){ 
                    fflag = 1;
                }
            }
            if(!fflag)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}