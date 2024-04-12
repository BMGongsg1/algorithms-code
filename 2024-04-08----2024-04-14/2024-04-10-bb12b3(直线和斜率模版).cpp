#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> nums;
    int x=20,y=21;
    for(int x1 = 0;x1<x;x1++)
    {
        cout<<x1<<endl;
        for(int y1 = 0;y1<y;y1++)
        {
            for(int x2=0;x2<x;x2++)
            {
                for(int y2 = 0;y2<y;y2++)
                {
                    int flag = 1,a2 = (y2-y1),b2 = (x1-x2),c2 = x2*y1-x1*y2;
                    if(x2==x1||y2==y1) continue;
                    for(int i=0;i<nums.size();i++)
                    {
                        int a1=nums[i][0],b1 = nums[i][1],c1=nums[i][2];
                        if((a1*b2==a2*b1)&&(a1*c2==a2*c1)&&(b1*c2==c1*b2))
                        {
                            // cout<<y2<<"  "<<y1<<"  "<<x2<<"  "<<x1<<"  "<<nums[i].second<<"  "<<nums[i].first<<endl;
                            flag = 0;
                        }
                    }
                    if(flag) {nums.push_back({a2,b2,c2});}
                }
            }
        }
    }
    cout<<nums.size()+x+y;
    return 0;
}