//P4290 [HAOI2008] 玩具取名
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int W,I,N,G;
    cin>>W>>I>>N>>G;
    vector<vector<vector<int>>> duizhao(4,vector<vector<int>>(4,vector<int>(4)));
    auto pd = [&](char a)->int{
        if(a == 'W') return 0;
        else if(a=='I') return 1;
        else if(a=='N') return 2;
        else return 3;
    };
    for(int i=0;i<W;i++)
    {
        string temp;
        cin>>temp;
        int fst=pd(temp[0]),sec=pd(temp[1]);
        duizhao[0][fst][sec] = 1;
    }
    for(int i=0;i<I;i++)
    {
        string temp;
        cin>>temp;
        int fst=pd(temp[0]),sec=pd(temp[1]);
        duizhao[1][fst][sec] = 1;
    }
    for(int i=0;i<N;i++)
    {
        string temp;
        cin>>temp;
        int fst=pd(temp[0]),sec=pd(temp[1]);
        duizhao[2][fst][sec] = 1;
    }
    for(int i=0;i<G;i++)
    {
        string temp;
        cin>>temp;
        int fst=pd(temp[0]),sec=pd(temp[1]);
        duizhao[3][fst][sec] = 1;
    }

    string str1;
    cin>>str1;
    str1 = " "+str1;

    vector<vector<vector<int>>> dp(str1.size(),vector<vector<int>>(str1.size(),vector<int>(4)));
    for(int i=1;i<str1.size();i++)
    {
        int x = pd(str1[i]);
        dp[i][i][x] = 1;
    }
    for(int i=str1.size()-2;i>=1;i--)
    {
        for(int j=i+1;j<str1.size();j++)
        {
            for(int k=i;k<j;k++)
            {
                for(int x=0;x<4;x++)
                {
                    for(int w=0;w<4;w++)
                    {
                        for(int o=0;o<4;o++)
                        {
                            if(dp[i][k][w]&&dp[k+1][j][o]&&duizhao[x][w][o])
                            {
                                dp[i][j][x] = 1;
                            }
                            // if(w==0&&o==0)
                            // {
                            //     cout<<dp[i][j][x]<<i<<"  "<<j<<" "<<x<<" "<<w<<"  "<<o<<endl;
                            // }
                            // if(dp[i][j][x]) cout<<i<<"  "<<j<<" "<<x<<" "<<w<<"  "<<o<<endl;
                        }
                    }
                }
            }
        }
    }
    
    // cout<<duizhao[1][0][0]<<endl;
    // cout<<dp[1][2][0]<<endl;
    // cout<<dp[3][4][0]<<endl;
    if(dp[1][str1.size()-1][0]) cout<<"W";
    if(dp[1][str1.size()-1][1]) cout<<"I";
    if(dp[1][str1.size()-1][2]) cout<<"N";
    if(dp[1][str1.size()-1][3]) cout<<"G";
    if(!dp[1][str1.size()-1][0]&&!dp[1][str1.size()-1][1]&&!dp[1][str1.size()-1][2]&&!dp[1][str1.size()-1][3]) cout<<"The name is wrong!"<<endl;
    
    return 0;
}