#include<bits/stdc++.h>
using namespace std;
vector<string> str(1100);
vector<int> nums(1100,INT_MAX);
vector<int> mapp(1025*1024);

int change(string &temp)
{
    sort(temp.begin(),temp.end());
    int ans = 0;
    for(int i=0;i<temp.size();i++)
    {
        ans = ans*26+(temp[i]-'a');
    }
    return ans;
}
int main()
{
    string origin;
    cin>>origin;
    for(int i=0;i<origin.size()-7;i++)
    {
        string temp = origin.substr(i,8);
        mapp[i] = change(temp);
    }  

    int s;
    cin>>s;
    for(int i=0;i<s;i++){
        cin>>str[i];
        nums[i] = change(str[i]);
    }

    sort(nums.begin(),nums.end());

    int ans = 0;
    for(int i=0;i<origin.size()-7;i++){
        int l,r;
        int left = 0,right = nums.size()-1;
        while(left<=right)
        {
            int mid = left+(right-left>>1);
            if(nums[mid]>=mapp[i])
            {
                right = mid - 1;
            }
            else left = mid + 1;
        }
        l = left;
        left = 0,right = nums.size()-1;
        while(left<=right){
            int mid = left+(right-left>>1);
            if(nums[mid]<=mapp[i])
            {
                left = mid + 1;
            }
            else right = mid - 1;
        }
        r = left-1;
        ans += (r-l+1);
        // cout<<r<<"  "<<l<<endl;
    }

    cout<<ans;

    return 0;
}