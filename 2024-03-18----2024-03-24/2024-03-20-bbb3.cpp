//2079: [蓝桥杯2023初赛] 冶炼金属
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    int maxx = INT_MAX,minn = 0;
    for(int i=0;i<n;i++)
    {
        int left=a[i].second-1;
        int right = a[i].first+1;
        while(left<=right)
        {
            // cout<<left<<"  "<<right<<endl;
            int mid = left+(right-left)/2;
            // cout<<mid<<endl;
            if(a[i].second<=a[i].first/mid)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        maxx = min(maxx,left-1);
        left = a[i].second-1;
        right = a[i].first+1;
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            if(a[i].first/mid<=a[i].second)

            
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        minn = max(minn,right+1);
    }
    cout<<minn<<" "<<maxx<<endl;
    return 0;
}