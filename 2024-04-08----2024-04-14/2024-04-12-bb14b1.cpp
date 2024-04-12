#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 100;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    set<int> sett;
    int ans = 0;
    for(int y1=0;y1<n;y1++){
        if(nums[y1]!=2) continue;
        for(int y2=y1+1;y2<n;y2++)
        {
            if(nums[y2]!=0) continue;
            for(int y3=y2+1;y3<n;y3++)
            {
                if(nums[y3]!=2) continue;
                for(int y4=y3+1;y4<n;y4++)
                {
                    if(nums[y4]!=3) continue;
                    for(int m1=y4+1;m1<n;m1++)
                    {
                        for(int m2=m1+1;m2<n;m2++)
                        {
                            if(nums[m2]+nums[m1]*10>12||nums[m2]+nums[m1]*10 == 0) continue;
                            for(int d1=m2+1;d1<n;d1++)
                            {
                                for(int d2=d1+1;d2<n;d2++)
                                {
                                    if(nums[d1]*10+nums[d2]==0||nums[d1]*10+nums[d2]>month[nums[m2]+nums[m1]*10]) continue;
                                    int temp = nums[d2]+nums[d1]*10+nums[m2]*100+nums[m1]*1000+nums[y4]*10000+nums[y3]*100000+nums[y2]*1000000+nums[y1]*10000000;
                                    if(sett.find(temp)!=sett.end())
                                    {
                                        continue;
                                    }
                                    sett.insert(temp);
                                    cout<<nums[y1]<<nums[y2]<<nums[y3]<<nums[y4]<<nums[m1]<<nums[m2]<<nums[d1]<<nums[d2]<<endl;
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}