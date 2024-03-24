//2077: [蓝桥杯2023初赛] 日期统计
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a(100);
    for(int i=0;i<a.size();i++)
    {
        cin>>a[i];
    }
    unordered_map<int,int> mapp;
    long long ans = 0;
    // cout<<a[98]<<a[99]<
    
    for(int i=0;i<a.size();i++)
    {
        for(int j=i+1;j<a.size();j++)
        {
            for(int k=j+1;k<a.size();k++)
            {
                for(int l=k+1;l<a.size();l++)
                {
                    if(a[i]!=2||a[j]!=0||a[k]!=2||a[l]!=3) continue;
                    for(int m=l+1;m<a.size();m++)
                    {
                        if((a[m]!=1&&a[m]!=0)) continue;
                        for(int mm=m+1;mm<a.size();mm++)
                        {
                            if(a[m]==1)
                            {
                                if(a[mm]>2) continue;
                            }
                            else if(a[m]==0)
                            {
                                if(a[mm] == 0) continue;
                            }
                            for(int d=mm+1;d<a.size();d++)
                            {
                                if(a[d]>3) continue;
                                for(int dd=d+1;dd<a.size();dd++)
                                {
                                    int month = a[m]*10+a[mm];
                                    int day = a[d]*10+a[dd];
                                    if(month==2)
                                    {
                                        if(day>28) continue;
                                        if(day == 0) continue;
                                    }
                                    else
                                    {
                                        if(day == 0) continue;
                                        if(month == 1||month==3||month==5||month==7||month==8||month==10||month==12)
                                        {
                                            if(day>31) continue;
                                        }
                                        else
                                        {
                                            if(day>30) continue;
                                        }
                                    }
                                    if(mapp.find(a[i]*10000000+a[j]*1000000+a[k]*100000+a[l]*10000+month*100+day)==mapp.end())
                                    {
                                        mapp[a[i]*10000000+a[j]*1000000+a[k]*100000+a[l]*10000+month*100+day]++;
                                        ans++;
                                        cout<<a[i]*10000000+a[j]*1000000+a[k]*100000+a[l]*10000+month*100+day<<endl;
                                    }
                                    // ans++;
                                    // cout<<a[i]*10000000+a[j]*1000000+a[k]*100000+a[l]*10000+month*100+day<<endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}