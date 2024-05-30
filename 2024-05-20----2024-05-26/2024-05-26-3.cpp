#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++) cin>>b[i];
    int maxx = 0;
    for(int i=0;i<n;i++) maxx = max(maxx,a[i] + b[i]);

    int left = 0,right = maxx,mid;
    while(left<=right)
    {
        mid = left + (right-left>>1);
        
        int tempm = m,flag =1;
        for(int i=0;i<n;i++)
        {
            if(a[i]+b[i]>=mid)
            {
                tempm -= mid - a[i];
            }
            else flag = 0;
            // cout<<i<<" "<<flag <<endl;
        }
        if(tempm<0) flag = 0;
        // cout<<left<<" "<<mid<<" "<<right<<"   "<<flag<<endl;
        if(flag)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout<<left-1;


    return 0;
}