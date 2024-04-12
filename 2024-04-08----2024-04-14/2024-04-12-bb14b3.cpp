#include<bits/stdc++.h>
using namespace std;
int main(){

    int maxx = 0;
    int n;
    cin>>n;
    vector<vector<int>> gold(n,vector<int>(2));
    for(int i=0;i<n;i++)
    {
        cin>>gold[i][0]>>gold[i][1];
        maxx = max(maxx,gold[i][0]);
    }

    int left = 0,right =maxx;
    while(left<=right)
    {
        int mid = left+(right-left>>1);
        int flag = 1;
        for(int i=0;i<n;i++)
        {
            if(mid*gold[i][1]>gold[i][0]) flag = 0;
        }
        if(flag == 0)
        {
            right = mid-1;
        }
        else 
        {
            left = mid+1;
        }
    }
    int maxx1 = left;

    left =0,right = maxx;
    while(left<=right)
    {
        int mid = left+(right-left>>1);
        int flag = 1;
        for(int i=0;i<n;i++)
        {
            if(gold[i][0]/mid<gold[i][1]) flag = 0;
        }
        if(flag == 0)
        {
            left = mid+1;
        }
        else 
        {
            right = mid-1;
        }
    }
    int minn = left;
    cout<<maxx1<<"  "<<minn<<endl;

    return 0;
}